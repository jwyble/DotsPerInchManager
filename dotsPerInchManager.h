#ifndef DOTSPERINCHMANAGER_H
#define DOTSPERINCHMANAGER_H

class DotsPerInchManager {
public:
	DotsPerInchManager() {
		init();
	};
	int getDotsPerInchX() {
		return _dotsPerInchX;
	};
	int getDotsPerInchY() {
		return _dotsPerInchY;
	};
	int scaleX(int x) {
		return MulDiv(x, _dotsPerInchX, 96);
	};
	int scaleY(int y) {
		return MulDiv(y, _dotsPerInchY, 96);
	};
	int unScaleX(int x) {
		return MulDiv(x, 96, _dotsPerInchX);
	};
	int unScaleY(int y) {
		return MulDiv(y, 96, _dotsPerInchY);
	};
	int scaledHeightOfScreen() {
		return scaledSystemMetricsY(SM_CYSCREEN);
	};
	int scaledWidthOfScreen() {
		return scaledSystemMetricsX(SM_CXSCREEN);
	};
	void scaleRect(__inout RECT* rect) {
		rect->left = scaleX(rect->left);
		rect->right = scaleY(rect->right);
		rect->top = scaleY(rect->top);
		rect->bottom = scaleY(rect->bottom);
	}
	void scalePoint(__inout POINT* point) {
		point->x = scaleX(point->x);
		point->y = scaleY(point->y);
	}
	void scaleSize(__inout SIZE* size) {
		size->cx = scaleX(size->cx);
		size->cy = scaleY(size->cy);
	}
	bool isLeastResolution(int cxMinimum, int cyMinimum) {
		return (scaledWidthOfScreen() >= cxMinimum) && (scaledHeightOfScreen() >= cyMinimum);
	}
	int pointsToPixels(int pt) {
		return MulDiv(pt, _dotsPerInchY, 72);
	};
	void invalidate() {
		init();
	};
private:
	int _dotsPerInchX = 0;
	int _dotsPerInchY = 0;
	void init() {
		HDC hDc = GetDC(NULL);

		if (hDc) {
			_dotsPerInchX = GetDeviceCaps(hDc, LOGPIXELSX);
			_dotsPerInchY = GetDeviceCaps(hDc, LOGPIXELSX);
			ReleaseDC(NULL, hDc);
		}
	};
	int scaledSystemMetricsX(int nMain) {
		return MulDiv(GetSystemMetrics(nMain), 96, _dotsPerInchX);
	};
	int scaledSystemMetricsY(int nMain) {
		return MulDiv(GetSystemMetrics(nMain), 96, _dotsPerInchY);
	};
};
#endif
