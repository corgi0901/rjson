#include <malloc.h>
#include <string.h>

#include "rjson.h"
#include "internal.h"

RJSON_TYPE rjson_get_type(rjson_t *json)
{
	return json == NULL ? RJSON_NULL : json->type;
}

void rjson_print(rjson_t *json)
{
	if (json == NULL)
		return;

	switch (json->type)
	{
	case RJSON_TRUE:
	{
		printf("true");
		break;
	}
	case RJSON_FALSE:
	{
		printf("false");
		break;
	}
	case RJSON_NULL:
	{
		printf("null");
		break;
	}
	case RJSON_NUMBER:
	{
		printf("%ld", json->content.number);
		break;
	}
	case RJSON_REAL:
	{
		printf("%f", json->content.real);
		break;
	}
	case RJSON_STRING:
	{
		printf("\"%s\"", json->content.str);
		break;
	}
	case RJSON_OBJECT:
	{
		object_t *object = json->content.object;

		printf("{");
		while (object)
		{
			printf("\"%s\":", object->key);
			rjson_print(object->value);
			if (object->next)
			{
				printf(",");
			}
			object = object->next;
		}
		printf("}");
		break;
	}
	case RJSON_ARRAY:
	{
		array_t *array = json->content.array;

		printf("[");
		while (array)
		{
			rjson_print(array->value);
			if (array->next)
			{
				printf(",");
			}
			array = array->next;
		}
		printf("]");
		break;
	}
	default:
		break;
	}
}

void rjson_free(rjson_t **json)
{
	if (*json == NULL)
		return;

	switch ((*json)->type)
	{
	case RJSON_STRING:
	{
		free((*json)->content.str);
		break;
	}
	case RJSON_OBJECT:
	{
		object_t *obj = (*json)->content.object;
		while (obj)
		{
			free(obj->key);
			rjson_free(&(obj->value));
			object_t *temp = obj;
			obj = obj->next;
			free(temp);
		}
		break;
	}
	case RJSON_ARRAY:
	{
		array_t *array = (*json)->content.array;
		while (array)
		{
			rjson_free(&(array->value));
			array_t *temp = array;
			array = array->next;
			free(temp);
		}
		break;
	}
	default:
		break;
	}

	free(*json);
	*json = NULL;
}