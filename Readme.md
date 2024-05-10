# PHP_SDL2 

Extension to create media application with PHP and C library SDL2

To compile need to run:
- `{PATH_TO_PHP}/bin/phpize`
- `./configure --with-php-config={PATH_TO_PHP}/bin/php-config`
- `make -jN && make install`
- `make test` for tests
- `php -dextension=php_sdl2 -m | grep php_sdl2` to check that ext loaded successfully


-jN - where N is a count of available processes (maxValue=cores x 2) for quick compilation


Additional info about an extension building:
https://www.phpinternalsbook.com/php7/build_system/building_extensions.html