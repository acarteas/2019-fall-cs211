#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "IndexedSort.h"
#include "../ADTs/Vector.h"
template <typename T>
class QuickSort : public IndexedSort<T>
{
private:
	int getPivot(Indexed<T> &data, int start_bound, int end_bound)
	{
		//assume best pivot is the starting index
		int pivot_index = start_bound;
		int mid_point = ((end_bound - start_bound) / 2) + start_bound;
		T start_value = data.getElementAt(start_bound);
		T mid_value = data.getElementAt(mid_point);
		T end_value = data.getElementAt(end_bound);

		//is the middle the best pivot?
		if (mid_value > start_value && mid_value < end_value)
		{
			pivot_index = mid_point;
		}
		else if (mid_value < start_value && mid_value > end_value)
		{
			pivot_index = mid_point;
		}

		//is end the best pivot?
		if (end_value > start_value && end_value < mid_value)
		{
			pivot_index = end_bound;
		}
		else if (end_value < start_value && end_value > mid_value)
		{
			pivot_index = end_bound;
		}
		return pivot_index;
	}
	void swap(Indexed<T> &data, int from, int to)
	{
		T temp = data.getElementAt(from);
		data.setElementAt(data.getElementAt(to), from);
		data.setElementAt(temp, to);
	}
	int findSmallerThan(Indexed<T> &data, T to_compare, int start_bound, int end_bound)
	{
		for (int i = end_bound; i >= start_bound; i--)
		{
			if (data.getElementAt(i) < to_compare)
			{
				return i;
			}
		}
		return start_bound - 1;
		
	}
	int findGreaterThan(Indexed<T> &data, T to_compare, int start_bound, int end_bound)
	{
		for (int i = start_bound; i <= end_bound; i++)
		{
			if (data.getElementAt(i) > to_compare)
			{
				return i;
			}
		}
		return end_bound + 1;
	}

	void sortHelper(Indexed<T> &data, int start_bound, int end_bound)
	{
        //base case not reached?
        if (end_bound - start_bound > 30)
        {
            //find the pivot
            int pivot = getPivot(data, start_bound, end_bound);
            T& pivot_value = data.getElementAt(pivot);

            //swap pivot with last element in array
            swap(data, pivot, end_bound);

            //set up i and j
            int i = start_bound;
            int j = end_bound - 1;

            //go until I and J cross
            while (i < j)
            {
                i = findGreaterThan(data, pivot_value, i, j);
                j = findSmallerThan(data, pivot_value, i, j);

                //are we not at the end?  If not, swap
                if (i < j)
                {
                    swap(data, i, j);
                }
            }

            //after loop, I must equal J.  Put pivot back.
            swap(data, i, end_bound);

            //recursive call
            if (start_bound < i - 1)
            {
                sortHelper(data, start_bound, i - 1);
            }
            if(end_bound > i + 1)
            {
                sortHelper(data, i + 1, end_bound);
            }
        }
        else
        {
            insertionSort(data, start_bound, end_bound);
        }
	}


	void insertionSort(Indexed<T> &data, int start_bound, int end_bound)
	{
        //we're starting at 1 becaues an array of size 1 (element 0) is
        //by definition sorted
        for (int i = start_bound + 1; i < end_bound; i++)
        {
            for (int j = i; j > 0; j--)
            {
                //out of order, swap
                if (data.getElementAt(j) < data.getElementAt(j - 1))
                {
                    T temp = data.getElementAt(j);
                    data.getElementAt(j) = data.getElementAt(j - 1);
                    data.getElementAt(j - 1) = temp;
                }
                else
                {
                    //no more comparisons to be made on this J loop
                    break;
                }
            }
        }
	}

public:
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		sortHelper(data, 0, data.getSize() - 1);
		return data;
	}

	
};

#endif