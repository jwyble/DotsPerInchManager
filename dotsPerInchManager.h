#ifndef DOTSPERINCHMANAGER_H
#define DOTSPERINCHMANAGER_H

class DotsPerInchManager {
public:
	DotsPerInchManager() {
		init();
	};
	/*
	  Get screen DPI-X
	*/
	int getDotsPerInchX() {
		return _dotsPerInchX;
	};
	/*
	  Get screen DPI-Y
	*/
	int getDotsPerInchY() {
		return _dotsPerInchY;
	};
	/*
	  Convert between raw pixels and relative pixels
	*/
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
	/*
	  Determine screen dimensions in relative pixels
	*/
	int scaledWidthOfScreen() {
		return scaledSystemMetricsX(SM_CXSCREEN);
	};
	int scaledHeightOfScreen() {
		return scaledSystemMetricsY(SM_CYSCREEN);
	};
	/*
	  Scale rectangle pixels from raw pixels to relative pixels
	*/
	void scaleRect(__inout RECT* rect) {
		rect->left = scaleX(rect->left);
		rect->right = scaleY(rect->right);
		rect->top = scaleY(rect->top);
		rect->bottom = scaleY(rect->bottom);
	}
	/*
	  Scale point pixels from raw pixels to relative pixels
	*/
	void scalePoint(__inout POINT* point) {
		point->x = scaleX(point->x);
		point->y = scaleY(point->y);
	}
	/*
	  Scale pixel size from raw pixels to relative pixels
	*/
	void scaleSize(__inout SIZE* size) {
		size->cx = scaleX(size->cx);
		size->cy = scaleY(size->cy);
	}
	/*
	  Determine if screen resolution meets requirements for relative pixels
	*/
	bool isLeastResolution(int cxMinimum, int cyMinimum) {
		return (scaledWidthOfScreen() >= cxMinimum) && (scaledHeightOfScreen() >= cyMinimum);
	}
	/*
	  Convert a point size to raw pixels
	  (these pixels are about 1/72 of an inch)
	*/
	int pointsToPixels(int pt) {
		return MulDiv(pt, _dotsPerInchY, 72);
	};
	/*
	  Invalidate any cached metrics
	*/
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
