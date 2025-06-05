//
// Created by eden on 6/5/25.
//

#ifndef MYCONTAINER_H
#define MYCONTAINER_H
#include <vector>
#include <iostream>

namespace Container{

    template<typename T = int>
    class MyContainer {
    private:
        std::vector<T> elements;

    public:
        void addElement(const T& element);
        void removeElement(const T& item);
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container);
    };

  template<typename T>
  void MyContainer<T>::addElement(const T& element){
        elements.push_back(element);
    }




}
#endif //MYCONTAINER_H
