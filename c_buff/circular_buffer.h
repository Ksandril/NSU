#pragma once

#include <stdexcept >
#include <cstdlib>
#include <algorithm>
////TODO хуйня - не работают удаление,ресайз и нью капасити + тесты!

template<class T>
class CircularBuffer {
private:
    T *buffer;
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;


public:
    using value_type = T;
    static size_t const default_size = 16u;

    CircularBuffer();

    ~CircularBuffer();

    CircularBuffer(const CircularBuffer &cb);

    //Конструирует буфер заданной ёмкости, целиком заполняет его элементом
    CircularBuffer(int capacity, const T &elem);

    //Конструирует буфер заданной ёмкости.
    explicit CircularBuffer(int capacity);

    //Оператор присваивания.
    CircularBuffer &operator=(const CircularBuffer &cb) {
        if (this != &cb) {
            CircularBuffer(cb).swap(&this);
        }
        return *this;
    }

    //Доступ по индексу. Не проверяют правильность индекса.
    T &operator[](int i) {
        return buffer[(front + i) % capacity];
    }

    const T &operator[](int i) const {
        return buffer[(front + i) % capacity];
    }

    //Доступ по индексу. Методы бросают исключение в случае неверного индекса.
    T &at(int i);

    const T &at(int i) const;

    //Ссылка на первый элемент
    T &get_front() {
        return buffer[front];
    }

    const T &get_front() const {
        return buffer[front];
    }

    //Ссылка на последний элемент.
    T &get_back() {
        return buffer[back];
    }

    const T &get_back() const {
        return buffer[back];
    }

    //Количество элементов, хранящихся в буфере.
    int get_size() const {
        return size;
    }

    //ёмкость буфера
    int get_capacity() const {
        return capacity;
    }

    //Количество свободных ячеек в буфере.
    int reserve() const {
        return capacity - size;
    }

    //true, если size() == capacity().
    bool full() const {
        return size == capacity;
    }

    //Проверяем, пустой ли буфер (если ёмкость = 0, то false)
    bool empty() const {
        return size;
    }

    //Добавляет элемент в конец буфера.
    //Если текущий размер буфера равен его ёмкости, то переписывается
    //первый элемент буфера (т.е., буфер закольцован).
    void push_back(const T &item = T());

    //Добавляет новый элемент перед первым элементом буфера.
    //Аналогично push_back, может переписать последний элемент буфера.
    void push_front(const T &item = T());

    //удаляет последний элемент буфера.
    void pop_back();

    //удаляет первый элемент буфера.
    void pop_front();

    //Сдвигает буфер так, что по нулевому индексу окажется элемент
    //с индексом new_begin.
    void rotate(int new_start) {
        std::rotate(buffer, buffer + new_start, buffer + capacity);
        back = back >= new_start ? back - new_start : capacity + back - new_start;
        front = front >= new_start ? front - new_start : capacity + front - new_start;
    }

    //Линеаризация - сдвинуть кольцевой буфер так, что его первый элемент
    //переместится в начало аллоцированной памяти. Возвращает указатель
    //на первый элемент.
    T *linearize() {////перепроверь
        std::rotate(buffer, buffer + front, buffer + capacity);
        back = back >= front ? back - front : capacity + back - front;
        front = 0;


        return buffer;
    }

    //Проверяет, является ли буфер линеаризованным.
    bool is_linearized() const {
        return front == 0;
    }

    void set_capacity(int new_capacity_);

    //Изменяет размер буфера.
    //В случае расширения, новые элементы заполняются элементом item.
    void resize(int new_size, const T &item = T());

    //Обменивает содержимое буфера с буфером cb.
    void swap(CircularBuffer &cb);

    //Вставляет элемент item по индексу pos.
    void insert(int pos, const T &item = T());

    //Удаляет элементы из буфера в интервале [first, last).
    void erase(int first, int last);

    //Очищает буфер.
    void clear() {
        size = back = 0;
        front = -1;
    }


    template<class T1>
    friend bool operator!=(const CircularBuffer<T> &a, const CircularBuffer<T> &b);

    template<class T1>
    friend bool operator==(const CircularBuffer<T> &a, const CircularBuffer<T> &b);


    ////функции для отладки
    void print_buffer() {
        for (size_t i = 0; i < capacity; ++i) {
            std::cout << buffer[i] << " ";
        }
    };

    void print_private() {
        std::cout << "[front] =" << front << std::endl;
        std::cout << "[back] =" << back << std::endl;
        std::cout << " size ==" << size << std::endl;
    }
};


//// (уъу, конструкторы)
template<class T>
CircularBuffer<T>::CircularBuffer() {
    front = -1;
    back = 0;
    size = 0;
    capacity = default_size;
    buffer = new T[default_size];
}


template<class T>
CircularBuffer<T>::CircularBuffer(int cap) {
    front = -1;
    back = 0;
    size = 0;
    capacity = cap;
    buffer = new T[capacity];
}


template<class T>
CircularBuffer<T>::CircularBuffer(int cap, const T &elem) {
    front = 0;
    capacity = cap;
    size = capacity;
    back = size - 1;
    buffer = new T[capacity];
    std::fill(buffer, buffer + size, elem);
}

template<class T>
CircularBuffer<T>::CircularBuffer(const CircularBuffer &cb) {
    size = cb.size;
    front = cb.front;
    back = cb.back;
    capacity = cb.capacity;
    buffer = new T[cb.capacity];
    std::copy(cb.buffer, cb.buffer + cb.size, buffer);
}

/// деструктор
template<class T>
CircularBuffer<T>::~CircularBuffer() {
    delete[]buffer;
}


template<class T>
void CircularBuffer<T>::swap(CircularBuffer &cb) {
    std::swap(buffer, cb.buffer);
    std::swap(capacity, cb.capacity);
    std::swap(size, cb.size);
    std::swap(front, cb.front);
    std::swap(back, cb.back);
}


/// УЪУ ПЕРЕГРУЗКА ОПЕРАТОРОВ ЧЕРЕЗ ДРУЗЕЙ
template<class T>
bool operator==(const CircularBuffer<T> &a, const CircularBuffer<T> &b) {
    if (a.size != b.size && a.back != b.back && a.front && b.front && a.capacity != b.capacity) return false;
    int aux = a.front;
    int end = a.back;
    while (aux != end) {
        if (a[aux] != b[aux]) return false;
        aux = (aux + 1) % a.capacity;
    }
    return true;

}

template<class T>
bool operator!=(const CircularBuffer<T> &a, const CircularBuffer<T> &b) {
    return !(a == b);
}


////получение элемента с проверкой
template<class T>
T &CircularBuffer<T>::at(int i) {
    if (!(front <= front + i && i <= front + size - 1)) {
        throw std::out_of_range("U WAT?");
    }
    return buffer[(front + i) % capacity];
}

template<class T>
const T &CircularBuffer<T>::at(int i) const {
    if (!(front <= front + i && i <= front + size - 1)) {
        throw std::out_of_range("U WAT?");
    }
    return buffer[(front + i) % capacity];
}


///уъУ Вставки и удаления

template<class T>
void CircularBuffer<T>::push_front(const T &item) {
    if (front == -1) { ///при инициализации пустого буфера
        front = 0;
        back = 0;
    } else front = front == 0 ? capacity - 1 : front - 1;
    size = full() ? size : size + 1;
    buffer[front] = item;
}

template<class T>
void CircularBuffer<T>::push_back(const T &item) {
    if (front == -1) {
        front = 0;
        back = 0;
    } else back = back == capacity - 1 ? 0 : back + 1;
    size = full() ? size : size + 1;
    buffer[back] = item;
}

template<class T>

void CircularBuffer<T>::insert(int pos, const T &item) {
    rotate(front);
    if (reserve() == 0) {
        T aux = buffer[back];
        for (size_t i = back; i > pos; i--) {
            buffer[i] = buffer[(i - 1)];
        }
        buffer[front] = aux;

    } else {

        for (size_t i = size; i > pos; i--) {
            buffer[i] = buffer[(i - 1)];
        }
        ++size;
    }
    buffer[pos] = item;


}

template<class T>
void CircularBuffer<T>::erase(int first, int last) {
    size_t count = last - first + 1;
    first = (front + first) % capacity;
    size_t counter = front + size - 1;
    for (size_t k = 0; k < count; ++k) {
        for (size_t i = first; i < counter; i++) {
            std::swap(buffer[i % capacity], buffer[(i + 1) % capacity]);
        }
    }

    back = back >= count ? back - count : capacity + back - count;

    size = size >= count ? size - count : capacity + size - count;
}


///исключение при удалении из пустой очереди  TODO
template<class T>
void CircularBuffer<T>::pop_front() {
    if (front == back) {
        back = back == 0 ? capacity - 1 : back - 1;
    }
    front = front == capacity - 1 ? 0 : front + 1;
    --size;
}

template<class T>
void CircularBuffer<T>::pop_back() {
    if (front == back) {
        front = front == capacity - 1 ? 0 : front + 1;
    }
    back = back == 0 ? capacity - 1 : back - 1;
    --size;
}


template<class T>
void CircularBuffer<T>::set_capacity(int new_capacity_) {
    if(capacity != new_capacity_) {
        T *new_buff = new T[new_capacity_];
        rotate(front);
        size_t copy_size = new_capacity_ < capacity ? new_capacity_ : capacity;
        std::copy(buffer, buffer + copy_size, new_buff);
        delete[] buffer;
        this->buffer = new_buff;
    }
}

template<class T>
void CircularBuffer<T>::resize(int new_size, const T &item) {
    rotate(front);
    capacity = new_size > capacity ? new_size : capacity;
    T *new_buff = new T[capacity];
    size_t copy_size;
    if (new_size > size) {
        copy_size = size;
        std::copy(buffer, buffer + copy_size, new_buff);
        std::fill(new_buff + copy_size, new_buff + new_size, item);
    } else {
        copy_size = new_size;
        std::copy(buffer, buffer + copy_size, new_buff);
    }
    delete[] buffer;
    this->buffer = new_buff;
    size = new_size;


}