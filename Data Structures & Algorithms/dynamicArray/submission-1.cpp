class DynamicArray {
   public:
    DynamicArray(int capacity) : m_capacity(capacity), m_size(0), m_arr(new int[capacity]) {
        for (size_t i = 0; i < m_capacity; i++) m_arr[i] = 0;
    }

    int get(int i) { return m_arr[i]; }

    void set(int i, int n) { m_arr[i] = n; }

    void pushback(int n) {
        if (m_size == m_capacity) {
            resize();
        }
        m_arr[m_size++] = n;
    }

    int popback() {
        // if (m_size == 0) return nullptr;
        return m_arr[--m_size];
    }

    void resize() {
        size_t new_cap = 2 * m_capacity;
        int* arr = new int[new_cap];

        for (size_t i = 0; i < new_cap; i++) {
            if (i < m_size)
                arr[i] = m_arr[i];
            else
                arr[i] = 0;
        }

        delete[] m_arr;

        m_arr = arr;
        m_capacity = new_cap;
    }

    int getSize() { return m_size; }

    int getCapacity() { return m_capacity; }

   private:
    int* m_arr;
    size_t m_size;
    size_t m_capacity;
};
