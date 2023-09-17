// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void print_pancake_sizes(int pancake_sizes[], int number_of_pancakes)
{
    for (int i = 0; i < number_of_pancakes; i++) {
        cout << pancake_sizes[i] << " ";
    }
    cout << endl;
}

void copy_array(int source[], int destination[], int start_index, int size)
{
    for (int i = 0; i < size; i++) {
        destination[i] = source[i + start_index];
    }
}

void flip_array(int items[], int end_position)
{
    int temp;
    for (int i = 0; i < end_position / 2; i++) {
        temp = items[i];
        items[i] = items[end_position - 1 - i];
        items[end_position - 1 - i] = temp;
    }
}

int main()
{
    // get number of pancakes ex. 5
    int number_of_pancakes;
    cin >> number_of_pancakes;

    // get pancake sizes ex. 3 1 2 5 4
    int pancake_sizes[number_of_pancakes];
    int sorted_sizes[number_of_pancakes];
    for (int i = 0; i < number_of_pancakes; i++) {
        cin >> pancake_sizes[i];
    }

    // sort pancake sizes descending ex. 5 4 3 2 1
    for (int i = 0; i < number_of_pancakes; i++) {
        sorted_sizes[i] = pancake_sizes[i];
    }
    int x = sizeof(sorted_sizes) / sizeof(sorted_sizes[0]);
    sort(sorted_sizes, sorted_sizes + x, greater<int>());

    // print initial pancake sizes ex. 3 1 2 5 4
    cout << "output" << endl;
    print_pancake_sizes(pancake_sizes, number_of_pancakes);

    for (int i = 0; i < number_of_pancakes - 1; i++) {
        // find pancakge size order by the largest to smallest ex. find 5 at first lopp, 4 at second loop, etc.
        int finding_size = sorted_sizes[i];

        // flag to check if the finding size is already on the top
        bool is_on_top = false;

        for (int j = 0; j < number_of_pancakes; j++) {
            if (finding_size == pancake_sizes[j]) {
                if (j == 0) {
                    // already on the top
                    is_on_top = true;
                    break;
                }

                if (i == number_of_pancakes - j - 1) {
                    // already in the correct position
                    // i is order by descending, while j is order by ascending
                    break;
                }

                // flip the pancakes between top and finding size ex. 3 1 2 -> 2 1 3
                int flip_pancakes[j];
                copy_array(pancake_sizes, flip_pancakes, 0, j);
                flip_array(flip_pancakes, j);

                // move the finding size to the top
                pancake_sizes[0] = finding_size;
                for (int k = 0; k < j; k++) {
                    pancake_sizes[k + 1] = flip_pancakes[k];
                }

                // first loop will be 5 2 1 3 4
                // cout << "  flip to top: ";
                print_pancake_sizes(pancake_sizes, number_of_pancakes);
                is_on_top = true;
                break;
            }
        }

        if (is_on_top) {
            // flip size will equal to the number of pancakess excluding the top and processed size
            // first loop, flip size will be 4 and array before flip is 2 1 3 4
            int flip_size = number_of_pancakes - i - 1;
            int flip_pancakes[flip_size];

            copy_array(pancake_sizes, flip_pancakes, 1, flip_size);
            flip_array(flip_pancakes, flip_size);

            pancake_sizes[flip_size] = pancake_sizes[0];
            copy_array(flip_pancakes, pancake_sizes, 0, flip_size);

            // cout << "  flip to correct position: ";
            print_pancake_sizes(pancake_sizes, number_of_pancakes);
        }
    }

    return 0;
}