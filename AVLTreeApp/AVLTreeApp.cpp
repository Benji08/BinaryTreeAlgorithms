#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "..\AVLTreeLib\AVLTree.h"
#include "..\benchmark\benchmark.h"

class Key
{
private:
	unsigned long value = 0UL;
	static bool performDelay;
	void delay() const
	{
		if (performDelay)
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
public:
	Key() = default;

	Key(Key const&) = default;

	Key(unsigned long v) : value(v)
	{
	}

	unsigned long getKey() const
	{
		return value;
	}

	static void delayOn()
	{
		performDelay = true;
	}

	static void delayOff()
	{
		performDelay = false;
	}


	bool operator==(Key const& v) const
	{
		delay();
        if(this == NULL)
            return false;
		return value == v.value;
	}

	bool operator!=(Key const& v) const
	{
		delay();
		return value != v.value;
	}

	bool operator<(Key const& v) const
	{
		delay();
		return value < v.value;
	}
	bool operator<=(Key const& v) const
	{
		delay();
		return value <= v.value;
	}
	bool operator>(Key const& v) const
	{
		delay();
		return value > v.value;
	}
	bool operator>=(Key const& v) const
	{
		delay();
		return value >= v.value;
	}

};

bool Key::performDelay = false;

std::ostream & operator << (std::ostream& stream, Key const& key)
{
	stream << key.getKey();
	return stream;
}

int main()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator((unsigned long)seed);

    size_t size;
    do
    {
        std::cout << "Enter size:";
        std::cin >> size;
        if (size > 0)
        {
            Key::delayOff();
            AVLTree<Key, unsigned long>  tree;
            while (tree.size2() < size)
            {
                unsigned int n = generator();
                Key key(n);
                tree.add(key, n);
            }
            if (tree.size2() <= 20)
                tree.inOrder();

            Key::delayOn();
            unsigned long long sum = 0;
            int i;
            for (i = 0; i < 10; ++i)
            {
                unsigned int n = generator();
                Key key(n);

                Benchmark<std::chrono::nanoseconds> b;
                tree.remove(key);
                sum += b.elapsed();
            }
            std::cout << "Time: " << sum / 10<<" ns" << "\n";
            std::cout << "Time: " << double(sum) / 10000000000<<" s"<< "\n";
        }
    } while (size > 0);
    return 0;
}
