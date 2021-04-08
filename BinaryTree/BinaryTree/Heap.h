#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapCreate(HpDataType* a, size_t n);
void HeapPush(Heap* hp);
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);

