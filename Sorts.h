#pragma once
#include "Sequence.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"

template <typename T>
Sequence <T>* bubble_sort(Sequence <T>* seq)
{
	for (int i = 0; i < seq->GetLength() - 1; i++)
	{
		for (int k = 0; k < seq->GetLength() - i - 1; k++)
		{
			if (seq->Get(k) > seq->Get(k + 1))
			{
				T tmp = seq->Get(k);
				seq->Set(seq->Get(k + 1), k);
				seq->Set(tmp, k + 1);
			}
		}
	}
	return seq;
}

template <typename T>
Sequence <T>* quick_sort(Sequence <T>* seq, int left, int right)
{
	T pivot{ seq->Get(left) };
	int leftBorder{ left };
	int rightBorder{ right };

	while (left < right)
	{
		while ((seq->Get(right) >= pivot) && (left < right)) right--;
		if (left != right)
		{
			seq->Set(seq->Get(right), left);
			left++;
		}
		while ((seq->Get(left) <= pivot) && (left < right)) left++;
		if (left != right)
		{
			seq->Set(seq->Get(left), right);
			right--;
		}
	}
	seq->Set(pivot, left);
	pivot = left;
	left = leftBorder;
	right = rightBorder;
	if (left < pivot)
		quick_sort(seq, left, pivot - 1);
	if (right > pivot)
		quick_sort(seq, pivot + 1, right);

	return seq;
}

template <typename T>
Sequence<T>* shell_sort(Sequence <T>* seq, int size)
{
	int step{ 0 };
	T tmp{ 0 };
	int j{ 0 };
	for (step = size / 2; step > 0; step /= 2)
	{
		for (int i(step); i < size; i++)
		{
			tmp = seq->Get(i);
			for (j = i; j >= step; j -= step)
			{
				if (tmp < seq->Get(j - step))
					seq->Set(seq->Get(j - step), j);
				else
					break;
			}
			seq->Set(tmp, j);
		}
	}
	return seq;
}





