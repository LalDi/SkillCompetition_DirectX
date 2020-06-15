#pragma once
	BOOL IsPointInRect(const D2D1_RECT_F rt, const D2D1_POINT_2F pt);
	BOOL IsPointInCircle(const D2D1_POINT_2F ptCircle, const int cr, const D2D1_POINT_2F pt);
	D2D1_RECT_F* rtIntersectRect(const D2D1_RECT_F rt1, const D2D1_RECT_F rt2);
	BOOL RectCrashCheck(const D2D1_RECT_F rt1, const D2D1_RECT_F rt2);
	BOOL CircleCrashCheck(D2D1_POINT_2F ptCircle1, int r1, D2D1_POINT_2F ptCircle2, int r2);
	BOOL RectCircleCrashCheck(D2D1_POINT_2F ptCircle, int r, const D2D1_RECT_F Rect);
