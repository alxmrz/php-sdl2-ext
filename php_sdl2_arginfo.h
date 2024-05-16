/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 35456f3e07edfe3350b9f5513336dd643b3b1399 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_GetError, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_Init, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_CreateWindow, 0, 6, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_CreateRenderer, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_UpdateWindowSurface, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_SetRenderDrawColor, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_RenderFillRect, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_RenderPresent, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_Delay, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_SDL_DestroyRenderer arginfo_SDL_RenderPresent

#define arginfo_SDL_Quit arginfo_SDL_RenderPresent

#define arginfo_SDL_DestroyWindow arginfo_SDL_RenderPresent


ZEND_FUNCTION(SDL_GetError);
ZEND_FUNCTION(SDL_Init);
ZEND_FUNCTION(SDL_CreateWindow);
ZEND_FUNCTION(SDL_CreateRenderer);
ZEND_FUNCTION(SDL_UpdateWindowSurface);
ZEND_FUNCTION(SDL_SetRenderDrawColor);
ZEND_FUNCTION(SDL_RenderFillRect);
ZEND_FUNCTION(SDL_RenderPresent);
ZEND_FUNCTION(SDL_Delay);
ZEND_FUNCTION(SDL_DestroyRenderer);
ZEND_FUNCTION(SDL_Quit);
ZEND_FUNCTION(SDL_DestroyWindow);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(SDL_GetError, arginfo_SDL_GetError)
	ZEND_FE(SDL_Init, arginfo_SDL_Init)
	ZEND_FE(SDL_CreateWindow, arginfo_SDL_CreateWindow)
	ZEND_FE(SDL_CreateRenderer, arginfo_SDL_CreateRenderer)
	ZEND_FE(SDL_UpdateWindowSurface, arginfo_SDL_UpdateWindowSurface)
	ZEND_FE(SDL_SetRenderDrawColor, arginfo_SDL_SetRenderDrawColor)
	ZEND_FE(SDL_RenderFillRect, arginfo_SDL_RenderFillRect)
	ZEND_FE(SDL_RenderPresent, arginfo_SDL_RenderPresent)
	ZEND_FE(SDL_Delay, arginfo_SDL_Delay)
	ZEND_FE(SDL_DestroyRenderer, arginfo_SDL_DestroyRenderer)
	ZEND_FE(SDL_Quit, arginfo_SDL_Quit)
	ZEND_FE(SDL_DestroyWindow, arginfo_SDL_DestroyWindow)
	ZEND_FE_END
};
