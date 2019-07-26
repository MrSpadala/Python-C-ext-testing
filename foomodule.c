#define PY_SSIZE_T_CLEAN
#include <Python.h>


static PyObject *
foo_PD(PyObject *self, PyObject *args)
{
	const char *cmd1, *cmd2;
	int ret_val;

	if (!PyArg_ParseTuple(args, "ss", &cmd1, &cmd2))
	{
		printf("two strings\n");
		return NULL;
	}

	ret_val = printf("%s CONCAT %s\n", cmd1, cmd2);

	return PyLong_FromLong(ret_val);
}


static PyObject *
foo_test(PyObject *self, PyObject *args)
{

	printf("Args length: %lu\n", PyObject_Length(args));

	PyObject* obj;
	PyObject* err;

	if (!PyArg_ParseTuple(args, "O", &obj))
	{
		return NULL;
	}

	PyTypeObject* type = Py_TYPE(obj);
	printf("obj type is: %s\n", type->tp_name);

	Py_ssize_t len = PyObject_Length(obj);
	if (len == -1)
	{
		printf("%s\n", "No len :(");
		PyErr_Clear();
	} else
	{
		printf("Length: %lu\n", len);

	}

	printf("Getting the list\n");
	PyListObject* list = (PyListObject*) obj;

	PyObject* elem_obj = PyList_GetItem(obj, 0);
	err = PyErr_Occurred();
	if (err)
		return NULL;

	long elem_long = PyLong_AsLong(elem_obj);
	err = PyErr_Occurred();
	if (err)
		return NULL;

	printf("elem: %lu\n", elem_long);

	return PyLong_FromSsize_t(Py_REFCNT(obj));
}



static PyMethodDef fooMethods[] = {
	{"PD", foo_PD, METH_VARARGS, "Nfa ncazzo"},
	{"test", foo_test, METH_VARARGS, "return obj refs"},
	{NULL, NULL, 0, NULL}
};


static struct PyModuleDef foomodule = {
	PyModuleDef_HEAD_INIT,
	"foo",
	NULL,
	-1,
	fooMethods
};


PyMODINIT_FUNC
PyInit_foo(void)
{
	return PyModule_Create(&foomodule);
}
