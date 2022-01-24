## const
```c++
class FooClass{
public:
    void Foo() const{ /*...*/}
private:
    /*...*/
};
```
- 成员函数Foo()有一个**隐士的形参this**，它是自身对象的一个指针，但是不能显示使用在Foo()形参列表里，加上const说明，this指向的对象是const对象；
- 声明const的成员函数，不能对调用它的对象内的成员进行修改【声明为mutable的成员除外】

*https://www.zhihu.com/question/27860418*

