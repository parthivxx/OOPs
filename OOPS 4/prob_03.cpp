#include <bits/stdc++.h>

using namespace std;

class Array
{
    int size;
    int *arr;

public:
    Array(int size = 0, int val = 0)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = val;
        }
    }
    Array(const Array &old_array)
    {
        size = old_array.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = old_array.arr[i];
    }
    Array operator*(int mul)
    {
        Array result;
        result.size = size;
        result.arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            result.arr[i] = mul * arr[i];
        }
        return result;
    }
    int operator[](int i)
    {
        return arr[i];
    }
    void operator=(Array b)
    {
        for (int i = 0; i < size; i++)
            arr[i] = b.arr[i];
    }
    Array operator+(Array b)
    {
        Array result;
        result.size = size;
        for (int i = 0; i < size; i++)
        {
            result.arr[i] = arr[i] + b.arr[i];
        }
        return result;
    }
    void change_value(int new_val)
    {
        for (int i = 0; i < size; i++)
            arr[i] = new_val;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    ~Array()
    {
        delete[] arr;
    }
    friend Array operator*(int, Array);
};
Array operator*(int mul, const Array obj)
{
    Array result;
    result.size = obj.size;
    result.arr = new int[obj.size];
    for (int i = 0; i < obj.size; i++)
    {
        result.arr[i] = mul * obj.arr[i];
    }
    return result;
}
int main()
{
    Array a(5, 3);
    Array b(5, 69);
    Array c = a + b;
    c.display();
    cout << b[4] << '\n';
    return 0;
}