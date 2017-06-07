#include "ruby.h"

VALUE $kernel;

void init()
{
    ruby_init();
    ruby_init_loadpath();
    //Init_enc();
    rb_require("rubygems");
    rb_require("sample"); // RUBYLIB=. ./sample
}

void test()
{
    VALUE module = rb_const_get(rb_cObject, rb_intern("Test"));
    VALUE klass = rb_const_get(module, rb_intern("Sample"));
    VALUE str = rb_str_new2("a");
    //VALUE object = rb_obj_alloc(klass);
    //rb_obj_call_init(object, 0, NULL);
    VALUE object = rb_class_new_instance(0, NULL, klass);
    printf("bar");
    //rb_funcall(object, rb_intern("puts"), 1, str);
    rb_funcall(object, rb_intern("puts"), 0);
    //int state;
    //VALUE value;
    //value = rb_eval_string_protect("puts 1", &state);
}

int main()
{
    init();
    test();
}
