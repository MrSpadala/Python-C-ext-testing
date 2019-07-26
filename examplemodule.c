
#define PY_SSIZE_T_CLEAN
#include <Python.h>


static PyObject *
example_test(PyObject *self, PyObject *args)
{
	PyObject *obj1, *obj2, *err;
	PyTypeObject *type;
	Py_ssize_t size;

	if (!PyArg_ParseTuple(args, "OO", &obj1, &obj2))
	{
		return NULL;
	}

	type = Py_TYPE(obj1);
	printf("obj1 type is: %s\n", type->tp_name);
	type = Py_TYPE(obj2);
	printf("obj2 type is: %s\n", type->tp_name);

	size = PyObject_Length(obj1);
	if (size == -1)
	{
		printf("%s\n", "obj1 has no len :(");
		PyErr_Clear();
	} else
		printf("Length obj1: %lu\n", size);

	size = PyObject_Length(obj2);
	if (size == -1)
	{
		printf("%s\n", "obj2 has no len :(");
		PyErr_Clear();
	} else
		printf("Length obj2: %lu\n", size);
	
	/*
	PyObject* elem_obj = PyList_GetItem(obj, 0);
	err = PyErr_Occurred();
	if (err)
		return NULL;

	long elem_long = PyLong_AsLong(elem_obj);
	err = PyErr_Occurred();
	if (err)
		return NULL;

	printf("elem: %lu\n", elem_long);
	*/

	size = Py_REFCNT(obj1);
	printf("obj1 reference counter: %lu\n", size);
	size = Py_REFCNT(obj2);
	printf("obj2 reference counter: %lu\n", size);

	Py_RETURN_NONE;
}



//
//

static PyMethodDef exampleMethods[] = {
	{"test", example_test, METH_VARARGS, "nfa ncazzo"},
	{NULL, NULL, 0, NULL}   // array terminator
};


static struct PyModuleDef examplemodule = {
	PyModuleDef_HEAD_INIT,
	"example",
	NULL,
	-1,
	exampleMethods
};


PyMODINIT_FUNC
PyInit_example(void)
{
	return PyModule_Create(&examplemodule);
}
