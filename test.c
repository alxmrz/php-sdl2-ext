//
// Created by alexandr on 16.05.24.
//

#include "php.h"
#include "ext/standard/info.h"
#include "php_php_sdl2.h"
#include "php_sdl2_arginfo.h"

#include "SDL2/SDL.h"

/*
function test1(): void {}

function test2(string $str = ""): string {}

function fooBar(string $str =  "Hello, World from FooBar"): string {}
function sdl2_sum (array $arr = []): int {}
function intArray(): array {}
 */


/* {{{ void test1() */
PHP_FUNCTION(test1)
        {
                ZEND_PARSE_PARAMETERS_NONE();

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            php_printf("Cant intitialize SDL: %s\n", SDL_GetError());
            return;
        }

        SDL_Window *window = SDL_CreateWindow(
        "Tetris with SDL2!",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_SHOWN);

        if (window == NULL) {
            php_printf("Can't create window: %s\n", SDL_GetError());
            return;
        }

        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL) {
            php_printf("Can't create renderer: %s\n", SDL_GetError());

            return;
        }

        SDL_UpdateWindowSurface(window);
        SDL_SetRenderDrawColor(renderer, 160, 160, 160, 0);
        SDL_Rect mainRect = {0, 0, 800, 600};

        if (SDL_RenderFillRect(renderer, &mainRect) < 0) {
            php_printf("Can't resresh canvas: (%s)", SDL_GetError());
            SDL_Quit();
            return ;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(5000);

        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        SDL_DestroyWindow(window);

        php_printf("The extension %s is loaded and working!\r\n", "php_sdl2");
        php_printf("The extension %s is loaded and working!\r\n", "php_sdl2");
        }

/* {{{ void test1() */
PHP_FUNCTION(fooBar)
        {
                char *var = "Hello, World from FooBar";
                size_t var_size = strlen(var);

                ZEND_PARSE_PARAMETERS_START(0, 1)
                Z_PARAM_OPTIONAL
                Z_PARAM_STRING(var, var_size)
                ZEND_PARSE_PARAMETERS_END();

                /*if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &var, &var_size) == FAILURE) {
                    return;
                }*/

                php_printf("The extension %s is loaded and working!\r\n",var);

                //RETURN_STR(var);
                RETURN_STRING(var);
        }


PHP_FUNCTION(sdl2_sum)
        {
                long result = 0;
                zval *data;
                HashTable *sum_args;

                ZEND_PARSE_PARAMETERS_START(0, 1)
                Z_PARAM_OPTIONAL
                Z_PARAM_ARRAY_HT(sum_args)
                ZEND_PARSE_PARAMETERS_END();

                if (zend_hash_num_elements(sum_args) == 0) {
                    return;
                }

                array_init_size(return_value, zend_hash_num_elements(sum_args));

                ZEND_HASH_FOREACH_VAL(sum_args, data)
                zval dup;
                ZVAL_COPY_VALUE(&dup, data);
                convert_to_long(&dup);
                result += Z_LVAL(dup);
                ZEND_HASH_FOREACH_END();
                /*if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &var, &var_size) == FAILURE) {
                    return;
                }*/


                //RETURN_STR(var);
                RETURN_LONG(result);
        }

PHP_FUNCTION(intArray)
        {
                long result = 0;
                zval *data;
                HashTable *sum_args;

                ZEND_PARSE_PARAMETERS_NONE();

                HashTable *arr = zend_new_array(0);
                php_printf("BEFORE INIT\r\n");

                zend_string *key1 = zend_string_init("key1", sizeof("key1")-1, 0);
                zval key1Zval;
                php_printf("BEFORE ZVAL\r\n");

                ZVAL_STRING(&key1Zval, "key1");

                php_printf("BEFORE ADD\r\n");

                zend_hash_add(arr, key1, &key1Zval);

                RETURN_ARR(arr);
        }


/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
        {
                char *var = "World";
                size_t var_len = sizeof("World") - 1;
                zend_string *retval;

                ZEND_PARSE_PARAMETERS_START(0, 1)
                Z_PARAM_OPTIONAL
                Z_PARAM_STRING(var, var_len)
                ZEND_PARSE_PARAMETERS_END();

                retval = strpprintf(0, "Hello %s", var);

                RETURN_STR(retval);
        }
/* }}}*/

