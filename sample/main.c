#include <stdio.h>
#include <rjson.h>

int main(void)
{
    rjson_t *json = rjson_object_create();
    rjson_object_add_number(json, "age", 32);
    rjson_object_add_string(json, "name", "Ryo Yoneyama");

    rjson_t *json2 = rjson_object_create_with_number("height", 178);
    rjson_object_add_string(json2, "sex", "male");
    rjson_object_add_true(json2, "true");
    rjson_object_add_false(json2, "false");
    rjson_object_add_null(json2, "null");

    rjson_object_add_value(json, "data", json2);

    rjson_t *array = rjson_array_create();
    rjson_array_add_string(array, "arr1");
    rjson_array_add_number(array, 120);

    rjson_t *json3 = rjson_object_create_with_value("height", rjson_array_create());

    rjson_array_add_value(array, json3);
    rjson_array_add_number(array, 456e3);
    rjson_array_add_real(array, 3.1415926535);
    rjson_array_add_true(array);

    rjson_object_add_value(json, "array", array);
    rjson_object_add_string(json, "end", "game");

    rjson_print(json);

    rjson_free(&json);

    printf("\n");

    return 0;
}