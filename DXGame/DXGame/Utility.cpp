#include "pch.h"

BOOL IsPointInRect(const D2D1_RECT_F rt, const D2D1_POINT_2F pt)
{
	if ((rt.left <= pt.x && rt.right >= pt.x) &&
		(rt.top <= pt.y && rt.bottom >= pt.y))
	{
		return TRUE;
	}

	return FALSE;
}

BOOL IsPointInCircle(const D2D1_POINT_2F ptCircle, const int cr, const D2D1_POINT_2F pt)
{
	float dx = ptCircle.x - pt.x;
	float dy = ptCircle.y - pt.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= cr) return TRUE;

	return FALSE;
}

D2D1_RECT_F* rtIntersectRect(const D2D1_RECT_F rt1, const D2D1_RECT_F rt2)
{
	D2D1_RECT_F* pIntersect = new D2D1_RECT_F();
	*pIntersect = D2D1_RECT_F{ 0,0,0,0 };

	if (rt1.left < rt2.right && rt1.right > rt2.left)
	{
		pIntersect->left = max(rt1.left, rt2.left);
		pIntersect->right = min(rt1.right, rt2.right);
	}
	if (rt1.top < rt2.bottom && rt1.bottom > rt2.top)
	{
		pIntersect->top = max(rt1.top, rt2.top);
		pIntersect->bottom = min(rt1.bottom, rt2.bottom);
	}

	return pIntersect;
}

BOOL RectCrashCheck(const D2D1_RECT_F rt1, const D2D1_RECT_F rt2)
{
	if (rt1.left < rt2.right &&
		rt1.top < rt2.bottom &&
		rt1.right > rt2.left&&
		rt1.bottom > rt2.top)
		return TRUE;
	return FALSE;
}

BOOL CircleCrashCheck(D2D1_POINT_2F ptCircle1, int r1, D2D1_POINT_2F ptCircle2, int r2)
{
	float dx = ptCircle1.x - ptCircle2.x;
	float dy = ptCircle1.y - ptCircle2.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= (r1 + r2)) return TRUE;

	return FALSE; 
}

BOOL RectCircleCrashCheck(D2D1_POINT_2F ptCircle, int r, const D2D1_RECT_F Rect)
{
	if (IsPointInRect(Rect, ptCircle))
	{
		D2D1_RECT_F temp = {
			Rect.left - r,
			Rect.top - r,
			Rect.right + r,
			Rect.bottom + r
		};
		if (IsPointInRect(temp, ptCircle))
			return TRUE;
	}
	else
	{
		if (IsPointInCircle(ptCircle, r, D2D1_POINT_2F{ Rect.left,	Rect.top	}))	return TRUE;
		if (IsPointInCircle(ptCircle, r, D2D1_POINT_2F{ Rect.left,	Rect.bottom }))	return TRUE;
		if (IsPointInCircle(ptCircle, r, D2D1_POINT_2F{ Rect.right, Rect.top	}))	return TRUE;
		if (IsPointInCircle(ptCircle, r, D2D1_POINT_2F{ Rect.right, Rect.bottom })) return TRUE;
	}
	return FALSE;
}