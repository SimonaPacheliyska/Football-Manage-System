#pragma once
template<typename T>
class Vector
{
public:
	Vector(T* data, size_t msize)
	{
		if (data != nullptr && msize > 0)
		{
			this->data = new T[msize];
			this->msize = this->capacity = msize;
			for (size_t i = 0; i < msize; i++)
			{
				this->data[i] = data[i];
			}
		}
		else
		{
			this->data = nullptr;
			this->msize = capacity = 0;
		}
	}

	Vector()
	{
		this->data = nullptr;
		this->msize = capacity = 0;
	}

	Vector(const Vector& other)
	{
		if (other.data != nullptr && other.msize > 0)
		{
			this->data = new T[other.msize];
			this->msize = this->capacity = other.msize;
			for (size_t i = 0; i < msize; i++)
			{
				this->data[i] = other.data[i];
			}
		}
		else
		{
			this->data = nullptr;
			this->msize = capacity = 0;
		}
	}

	Vector& operator=(const Vector& rhs)
	{
		if (rhs.data != nullptr && rhs.msize > 0)
		{
			this->data = new T[rhs.msize];
			this->msize = this->capacity = rhs.msize;
			for (size_t i = 0; i < msize; i++)
			{
				this->data[i] = rhs.data[i];
			}
		}
		else
		{
			this->data = nullptr;
			this->msize = capacity = 0;
		}
		return *this;
	}

	~Vector()
	{
		delete[] this->data;
	}

	T& operator[](size_t idx)
	{
		return this->data[idx];
	}

	const T& operator[](size_t idx) const
	{
		return this->data[idx];
	}
	
	void push_back(const T& element)
	{
		if ((this->msize + 1) > capacity)
		{
			if (capacity == 0)
			{
				this->capacity = 1;
			}
			resize(capacity * 2);
		}

		this->data[msize] = element;
		this->msize++;
	}

	size_t size()const
	{
		return this->msize;
	}

private:
	T* data;
	size_t msize;
	size_t capacity;

	void resize(size_t newCapacity)
	{
		T* temp = new T[newCapacity];
		for (size_t i = 0; i < msize; i++)
		{
			temp[i] = this->data[i];
		}
		delete[] this->data;
		this->data = temp;
		this->capacity = newCapacity;
	}
	

}; 
