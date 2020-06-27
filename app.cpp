// [COMPUTER ARCHITECTURE|EEE3530]
// written by SukJoon Oh, 2018142216, Yonsei Univ. EE
// For more repos, visit https://github.com/dev-acoustikue
// acoustikue@yonsei.ac.kr
//
// Tested on Windows 10 Pro, Visual Studio 2017 Professional

#include <iostream>
#include <list>

#define HITS std::cout << "\tHIT\n"
#define MISS std::cout << "\tMISS\n"

#define CACHE_INDEX_SIZE 1024

//#define HITS	;
//#define MISS	;

void q1_1_sim(int loops)
{

	// direct mapped
	int hits = 0;
	int misses = 0;

	int cache[CACHE_INDEX_SIZE] = {
		0,
	};

	const int base_a = 133;
	const int base_b = 133;

	int arr_idx = 0;
	for (int i = 0; i < loops; i++)
	{
		std::cout << "Iteration: " << i + 1 << ", i = " << i << std::endl;

		// 1. access b[4 * i]
		arr_idx = (base_b + (4 * i) / 4) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('b' + (4 * i) / 4))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('b' + (4 * i) / 4);
			MISS;
			misses++;
		}

		// 2. access a[6 * i]
		arr_idx = (base_a + (6 * i) / 4) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('a' + (6 * i) / 4))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('a' + (6 * i) / 4);
			MISS;
			misses++;
		}

		// 3. access b[i]
		arr_idx = (base_b + (i) / 4) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('b' + (i) / 4))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('b' + (i) / 4);
			MISS;
			misses++;
		}

		// 4. access a[2000 - i]
		arr_idx = (base_a + (2000 - i) / 4) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('a' + (2000 - i) / 4))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('a' + (2000 - i) / 4);
			MISS;
			misses++;
		}

		getchar();
	}

	std::cout << "\nhits: " << hits << std::endl;
	std::cout << "misses: " << misses << std::endl;
}

void q1_2_sim(int loops)
{
	// direct mapped
	int hits = 0;
	int misses = 0;

	const int index = CACHE_INDEX_SIZE / 4;
	std::list<int> cache[index];

	const int base_a = 133;
	const int base_b = 133;

	int arr_idx = 0;
	int list_cnt = 0;
	for (int i = 0; i < loops; i++)
	{
		std::cout << "Iteration: " << i + 1 << ", i = " << i << std::endl;

		// 1. access b[4 * i]
		list_cnt = 0;
		arr_idx = (base_b + (4 * i) / 4) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('b' + (4 * i) / 4))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			} // LRU
			cache[arr_idx].push_back(('b' + (4 * i) / 4));
			MISS;
			misses++;
		}

		// 2. access a[6 * i]
		list_cnt = 0;
		arr_idx = (base_a + (6 * i) / 4) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('a' + (6 * i) / 4))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			}
			cache[arr_idx].push_back(('a' + (6 * i) / 4));
			MISS;
			misses++;
		}

		// 3. access b[i]
		list_cnt = 0;
		arr_idx = (base_b + (i) / 4) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('b' + (i) / 4))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			}
			cache[arr_idx].push_back(('b' + (i) / 4));
			MISS;
			misses++;
		}

		// 4. access a[2000 - i]
		list_cnt = 0;
		arr_idx = (base_a + (2000 - i) / 4) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('a' + (2000 - i) / 4))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			}
			cache[arr_idx].push_back(('a' + (2000 - i) / 4));
			MISS;
			misses++;
		}
		//getchar();
	}

	std::cout << "\nhits: " << hits << std::endl;
	std::cout << "misses: " << misses << std::endl;
}

void q1_3_sim(int loops)
{

	// direct mapped
	int hits = 0;
	int misses = 0;

	int cache[CACHE_INDEX_SIZE] = {
		0,
	};

	const int base_a = 133;
	const int base_b = 133;

	int arr_idx = 0;
	for (int i = 0; i < loops; i++)
	{
		std::cout << "Iteration: " << i + 1 << ", i = " << i << std::endl;

		// 1. access b[4 * i]
		arr_idx = (base_b + (4 * i) / 16) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('b' + (4 * i) / 16))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('b' + (4 * i) / 16);
			MISS;
			misses++;
		}

		// 2. access a[6 * i]
		arr_idx = (base_a + (6 * i) / 16) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('a' + (6 * i) / 16))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('a' + (6 * i) / 16);
			MISS;
			misses++;
		}

		// 3. access b[i]
		arr_idx = (base_b + (i) / 16) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('b' + (i) / 16))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('b' + (i) / 16);
			MISS;
			misses++;
		}

		// 4. access a[2000 - i]
		arr_idx = (base_a + (2000 - i) / 16) % CACHE_INDEX_SIZE;
		if (cache[arr_idx] == ('a' + (2000 - i) / 16))
		{
			hits++;
			HITS;
		}
		else
		{
			cache[arr_idx] = ('a' + (2000 - i) / 16);
			MISS;
			misses++;
		}

		//getchar();
	}

	std::cout << "\nhits: " << hits << std::endl;
	std::cout << "misses: " << misses << std::endl;
}

void q1_4_sim(int loops)
{
	// direct mapped
	int hits = 0;
	int misses = 0;

	const int index = CACHE_INDEX_SIZE / 4;
	std::list<int> cache[index];

	const int base_a = 133;
	const int base_b = 133;

	int arr_idx = 0;
	int list_cnt = 0;
	for (int i = 0; i < loops; i++)
	{
		std::cout << "Iteration: " << i + 1 << ", i = " << i << std::endl;

		// 1. access b[4 * i]
		list_cnt = 0;
		arr_idx = (base_b + (4 * i) / 16) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('b' + (4 * i) / 16))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			} // LRU
			cache[arr_idx].push_back(('b' + (4 * i) / 16));
			MISS;
			misses++;
		}

		// 2. access a[6 * i]
		list_cnt = 0;
		arr_idx = (base_a + (6 * i) / 16) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('a' + (6 * i) / 16))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			}
			cache[arr_idx].push_back(('a' + (6 * i) / 16));
			MISS;
			misses++;
		}

		// 3. access b[i]
		list_cnt = 0;
		arr_idx = (base_b + (i) / 4) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('b' + (i) / 16))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 16)
			{
				cache[arr_idx].pop_front();
			}
			cache[arr_idx].push_back(('b' + (i) / 16));
			MISS;
			misses++;
		}

		// 4. access a[2000 - i]
		list_cnt = 0;
		arr_idx = (base_a + (2000 - i) / 16) % index;
		for (auto elm : cache[arr_idx])
		{ // find
			if (elm == ('a' + (2000 - i) / 16))
			{
				HITS;
				hits++;
				break;
			} // when hit
			else
			{
				list_cnt++;
			}
		}
		if (list_cnt == cache[arr_idx].size())
		{ // When miss
			if (list_cnt == 4)
			{
				cache[arr_idx].pop_front();
			}
			cache[arr_idx].push_back(('a' + (2000 - i) / 16));
			MISS;
			misses++;
		}
		//	getchar();
	}

	std::cout << "\nhits: " << hits << std::endl;
	std::cout << "misses: " << misses << std::endl;
}

int main()
{

	// Q1-1 10 iterations
	q1_1_sim(10);
	getchar();

	// Q1-1 2000 iterations
	q1_1_sim(2000);
	getchar();

	// Q1-2 10 iterations
	q1_2_sim(10);
	getchar();

	// Q1-2 2000 iterations
	q1_2_sim(2000);
	getchar();

	// Q1-3 10 iterations
	q1_3_sim(10);
	getchar();

	// Q1-3 2000 iterations
	q1_3_sim(2000);
	getchar();

	// Q1-4 10 iterations
	q1_4_sim(10);
	getchar();

	// Q1-4 2000 iterations
	q1_4_sim(2000);
	getchar();

	return 0;
};
