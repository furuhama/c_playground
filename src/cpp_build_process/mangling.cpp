extern "C" int add_c(int a, int b)
{
    return a + b;
}

int add(int a, int b)
{
    return a + b;
}

int add(const int *a, const int &b)
{
    return *a + b;
}

float add(float a, float b)
{
    return a + b;
}

namespace manu
{
    int add(int a, int b)
    {
        return a + b;
    }
}

int main() {
    return 0;
}
