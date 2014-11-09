# Modern C++ don't fear the auto
## C++ has changed a lot in recent years and is not like language you learned in school.
c++98, templates everywhere & naked pointers vs c++14 shared_ptr, raii & auto
https://www.youtube.com/watch?v=xnqTKD8uD64 13:36
```
// C++98
widget* factory();
void caller() {
    widget* w = factory();
    gadget* g = new gadget();
    use(*w, *g);
    delete g;
    delete w;
}

// Modern C++
unique_ptr<widget> factory();
void caller() {
    auto w = factory();
    auto g = make_unique<gadget>();
    use(*w, *g);
}
```

Still ok to pass a pointer/reference around but not to use new/delete to manage ownership.

A tour of c++ <-- på kindle

## auto
Resolved during compile, type infered based on usage  
creates a new object (copy) unless const, & or * is specified
https://www.youtube.com/watch?v=wQxj20X-tIU

## lambda
``[](int x, int y) -> int { return x + y; }`` 
or in c++14
``[](auto x, auto y) -> auto { return x + y; };``
same as
```
struct unnamed_lambda
{
  template<typename T, typename U>
    auto operator()(T x, U y) const {return x + y;}
};
auto lambda = unnamed_lambda{};
```
http://stackoverflow.com/questions/17233547/how-does-generic-lambda-work-in-c14
Capture ? 

## range based loop
``for(auto i : range) { } ``
ie
```
auto loop() {
    auto vec = {1,2,3,4,5};

    for(auto e : vec) {
        cout << e << endl;
    }
}
```
http://www.cprogramming.com/c++11/c++11-ranged-for-loop.html

## RAII ?
Resource Acquisition Is Initialization,
http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization

## Smart pointers
Use to manage ownership, uniqe_ptr is for a single owner, shared_ptr for cases with shared owernship
shared_ptr / uniqe_ptr -> make_shared / make_unique

## move construtor / rvalue reference
http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

## macro ?
``#define true false``

## bandit
```
go_bandit([](){
    describe("fuzzbox:", [](){
      guitar_ptr guitar;

      before_each([&](){
        guitar = guitar_ptr(new struct guitar());
      });

      it("starts in clean mode", [&](){
        AssertThat(guitar->sound(), Equals(sounds::clean));
      });
    });
});
```

## frankie
```
module(main, {
    Get("/Baz", [](auto context){
        auto p = context.parameters();
        return "baz" + p["foo"];
    });
    Post("/Foo", [](auto){
        return "foo";
    });
});
```


