/* php_sdl2 extension for PHP (c) 2024 alxmrz */

#ifndef PHP_PHP_SDL2_H
# define PHP_PHP_SDL2_H

extern zend_module_entry php_sdl2_module_entry;
# define phpext_php_sdl2_ptr &php_sdl2_module_entry

# define PHP_PHP_SDL2_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PHP_SDL2)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PHP_SDL2_H */
