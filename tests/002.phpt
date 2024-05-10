--TEST--
test1() Basic test
--EXTENSIONS--
php_sdl2
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension php_sdl2 is loaded and working!
NULL
