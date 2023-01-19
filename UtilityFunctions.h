#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>



template <typename T>
T RandomNumber(T min, T max)
{
	return (T(rand()) / T(RAND_MAX) * (max - min) + min);
}

template <typename T>
T RandomNumber(T max)
{
	return (T(rand()) / T(RAND_MAX) * (max - 0) + 0);
}

template <typename T>
inline T lerp(T v0, T v1, T t)
{
    return (1-t)*v0 + t*v1;
}

inline double Range(double n, double start1, double stop1, double start2, double stop2) {
	return ((n - start1) / (stop1 - start1))*(stop2 - start2) + start2;
};

template <typename T>
void RemoveAt(std::vector<T> V, int index)
{
	V.erase(V.begin() + index);
}

template <typename T>
std::vector<T> AddRange(std::vector<T> A, std::vector<T> B)
{
	std::vector<T> AB;
	AB.reserve(A.size() + B.size()); // preallocate memory
	AB.insert(AB.end(), A.begin(), A.end());
	AB.insert(AB.end(), B.begin(), B.end());
	return AB;
}

template <typename A, typename B>
A constrain(A n, B low, B high) {
	return std::max(std::min(n, high), low);
};

template <typename T>
void delete_pointed_to(T* const ptr) {
	delete ptr;
}

template <typename T>
void free_pointer_vector_memory(std::vector<T*> ptr_vector) {
	std::for_each(ptr_vector.begin(), ptr_vector.end(), delete_pointed_to<T>);
}


inline Vector2f RandomVector(float mag)
{
	return Vector2f{RandomNumber(-1*mag, 1*mag),RandomNumber(-1*mag, 1*mag)};
}