--TEST--
Check if php_sdl2 is loaded
--EXTENSIONS--
php_sdl2
--FILE--
<?php
echo 'The extension "php_sdl2" is available';
?>
--EXPECT--
The extension "php_sdl2" is available
