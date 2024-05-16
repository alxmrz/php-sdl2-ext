/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 37b644bea2731c1456a0a9eee7b428f5fa0b125a */

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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_RenderFillRect, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, rect, SDL_Rect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_RenderPresent, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_SDL_Delay, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_SDL_DestroyRenderer arginfo_SDL_RenderPresent

#define arginfo_SDL_Quit arginfo_SDL_RenderPresent

#define arginfo_SDL_DestroyWindow arginfo_SDL_RenderPresent

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_SDL_Rect___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()


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
ZEND_METHOD(SDL_Rect, __construct);


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


static const zend_function_entry class_SDL_Rect_methods[] = {
	ZEND_ME(SDL_Rect, __construct, arginfo_class_SDL_Rect___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_SDL_Rect(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "SDL_Rect", class_SDL_Rect_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	zval property_x_default_value;
	ZVAL_UNDEF(&property_x_default_value);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_UNDEF(&property_y_default_value);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_name);

	zval property_width_default_value;
	ZVAL_UNDEF(&property_width_default_value);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_UNDEF(&property_height_default_value);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	return class_entry;
}
