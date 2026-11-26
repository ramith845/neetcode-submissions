#include <cassert>
#include <stdexcept>
#include <utility>
class DynamicArray {
   public:
    explicit DynamicArray(int capacity) : m_arr(nullptr), m_size(0), m_capacity(capacity) {
        if (capacity <= 0) throw std::invalid_argument("capacity must be greater than 0");
        m_arr = new int[capacity];
    }

    DynamicArray(const DynamicArray& arr) = delete;
    DynamicArray& operator=(const DynamicArray& arr) = delete;

    DynamicArray(DynamicArray&& arr) noexcept
        : m_arr(std::exchange(arr.m_arr, nullptr)),
          m_size(std::exchange(arr.m_size, 0)),
          m_capacity(std::exchange(arr.m_capacity, 0)) {}

    DynamicArray& operator=(DynamicArray&& arr) noexcept {
        if (this != &arr) {
            delete[] m_arr;
            m_arr = std::exchange(arr.m_arr, nullptr);
            m_capacity = std::exchange(arr.m_capacity, 0);
            m_size = std::exchange(arr.m_size, 0);
        }
        return *this;
    }

    ~DynamicArray() { delete[] m_arr; }

    int get(int i) const {
        if (i < 0 || static_cast<size_t>(i) >= m_size)
            throw std::out_of_range("index out of bounds");
        return m_arr[i];
    }

    void set(int i, int n) {
        if (i < 0 || static_cast<size_t>(i) >= m_size)
            throw std::out_of_range("index out of bounds");
        m_arr[i] = n;
    }

    void pushback(int n) {
        if (m_size == m_capacity) {
            resize();
        }
        m_arr[m_size++] = n;
    }

    int popback() {
        assert(m_size > 0 && "Array is empty");
        return m_arr[--m_size];
    }

    void resize() {
        size_t new_cap = m_capacity == 0 ? 1 : 2 * m_capacity;
        int* arr = new int[new_cap];

        for (size_t i = 0; i < m_size; i++) {
            arr[i] = m_arr[i];
        }

        delete[] m_arr;

        m_arr = arr;
        m_capacity = new_cap;
    }

    int getSize() const { return static_cast<int>(m_size); }

    int getCapacity() const { return static_cast<int>(m_capacity); }

   private:
    int* m_arr;
    size_t m_size;
    size_t m_capacity;
};
