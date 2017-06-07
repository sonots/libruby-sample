#include "ruby.h"

VALUE $kernel;

void init()
{
    ruby_init();
    ruby_init_loadpath();
    //Init_enc();
    rb_require("rubygems");
    rb_require("./callee.rb");
}

void run()
{
    VALUE module = rb_const_get(rb_cObject, rb_intern("Test"));
    VALUE klass = rb_const_get(module, rb_intern("Callee"));
    VALUE str = rb_str_new2("a");
    VALUE obj = rb_class_new_instance(0, NULL, klass);
    rb_funcall(obj, rb_intern("foo"), 1, str);
}

int main()
{
    init();
    run();
}
