#include <iostream>

void print_array(double *array, std::size_t const capacity);
int main();

void print_array(double *array, std::size_t const capacity)
{
    if (capacity != 0)
    {
        std::cout << array[0];
        for (std::size_t i{1}; i < capacity; ++i)
        {
            std::cout << ", " << array[i];
        }
        std::cout << std::endl;
    }
}

int main()
{
    // allocation
    std::size_t data_capacity{10};
    double *data{new double[data_capacity]{}};
    std::size_t data_size{0};

    // usage
    while (true)
    {
        double x{};
        std::cout << "Enter a number (<=0 to quit): ";
        std::cin >> x;

        if (x <= 0)
            break;

        // reallocation - to extend array capacity
        if (data_size == data_capacity)
        {
            std::size_t old_capacity{data_capacity};
            double *old_data{data};
            data_capacity *= 2;
            data = new double[data_capacity]{};

            for (std::size_t i{0}; i < old_capacity; ++i)
            {
                data[i] = old_data[i];
            }

            delete[] old_data;
            old_data = nullptr;
        }

        data[data_size] = x;
        ++data_size;
    }
    print_array(data, data_capacity);

    // deallocation
    for (std::size_t i{0}; i < data_capacity; ++i)
    {
        data[i] = 0.0;
    }
    delete[] data;
    data = nullptr;

    return 0;
}