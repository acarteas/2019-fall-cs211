#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "IndexedSort.h"

template <typename T>
class BubbleSort : public IndexedSort<T>
{
public:

	//see http://en.wikipedia.org/wiki/Bubble_sort for a 
	//Bubble Sort implementation
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
        bool is_sorted = false;
        for (int i = 0; i < data.getSize() && is_sorted == false; i++)
        {
            is_sorted = true;
            for (int j = 0; j < data.getSize() - i - 1; j++)
            {
                if (data.getElementAt(j) > data.getElementAt(j + 1))
                {
                    //j is larger than j + 1, allow i to bubble up
                    T temp = data.getElementAt(j);
                    data.getElementAt(j) = data.getElementAt(j + 1);
                    data.getElementAt(j + 1) = temp;
                    is_sorted = false;
                }
            }
        }
		return data;
	}
};

#endif
