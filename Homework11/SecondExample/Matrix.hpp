#include <vector>
    namespace my {
    template <typename T>
    class Matrix {
        std::vector<std::vector<T>> matrix;
        //implementation
        public:
            // Что вернуть? std::vector& не хочется, раскрывается внутреннее состояние.
            //? operator[](int) const;
            // Proxy
            
            struct ProxyRow {
                std::vector<T> row;
                const T& operator[](int n) const { return row[n]; }
                T& operator[](int n) { return row[n]; }
            };

            ProxyRow operator[](int n) {
                return matrix[n];
            }

    };
}