#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    if (PyList_Check(p)) {
        Py_ssize_t size = PyList_Size(p);
        Py_ssize_t allocated = ((PyListObject *)p)->allocated;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %ld\n", size);
        printf("[*] Allocated = %ld\n", allocated);

        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *item = PyList_GetItem(p, i);
            const char *typeName = Py_TYPE(item)->tp_name;
            printf("Element %ld: %s\n", i, typeName);
        }
    } else {
        fprintf(stderr, "Invalid Python list object\n");
    }
}

void print_python_bytes(PyObject *p) {
    if (PyBytes_Check(p)) {
        Py_ssize_t size = PyBytes_Size(p);
        printf("[.] bytes object info\n");
        printf("  size: %ld\n", size);
        printf("  trying string: %s\n", PyBytes_AsString(p));

        printf("  first %ld bytes:", size + 1 > 10 ? 10 : size + 1);
        for (Py_ssize_t i = 0; i < (size + 1 > 10 ? 10 : size + 1); i++) {
            printf(" %02x", (unsigned char)PyBytes_AsString(p)[i]);
        }
        printf("\n");
    } else {
        fprintf(stderr, "Invalid bytes object\n");
    }
}


