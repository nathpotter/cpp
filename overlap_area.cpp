#include <iostream>
#include <vector>

using namespace std;

/// @brief Class to represent area (x1, y1) to (x2, y2)
///              +-----------------+ (x2, y2)
///              |                 |
///              |                 |
///     (x1, y1) +-----------------+
class area
{
    public:
        int x1, y1, x2, y2;

        /// @brief Constructor
        /// @param x1 
        /// @param y1 
        /// @param x2 
        /// @param y2 
        area(int x1, int y1, int x2, int y2)
        {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        /// @brief Get overlap size with other area
        int overlap_size(area other_area)
        {
            //            @@@@@@@@@@@@@@@@
            //            @@@@@@@@@@@+++++######
            //            @@@@@@@@@@@+++++######
            //                       ###########
            //                       ###########
            // @ is area
            // # is other area
            // + is overlap

            // overlap axis x if min x <= other area max x and max x >= other area min x
            //      min x @@@@@@@@@@@@@@@@ max x
            //      other area min x ########### other area max x
            //                       +++++ overlap
            int min_x = min(this->x1, this->x2);
            int max_x = max(this->x1, this->x2);
            int other_area_min_x = min(other_area.x1, other_area.x2);
            int other_area_max_x = max(other_area.x1, other_area.x2);
            
            int overlap_x = min(max_x, other_area_max_x) - max(min_x, other_area_min_x);
            if (overlap_x <= 0)
            {
                return 0;
            }
            
            // overlap axis y if min y <= other area max y and max y >= other area min y
            //      max y @
            //            @          # other area max y    + overlap
            //      min y @          #                     +
            //                       # other area min y
            int min_y = min(this->y1, this->y2);
            int max_y = max(this->y1, this->y2);
            int other_area_min_y = min(other_area.y1, other_area.y2);
            int other_area_max_y = max(other_area.y1, other_area.y2);

            int overlap_y = min(max_y, other_area_max_y) - max(min_y, other_area_min_y);
            if (overlap_y <= 0)
            {
                return 0;
            }

            return overlap_x * overlap_y;
        }
};

/// @brief Class to represent overlap information
class overlap_info
{
    public:
        int area1, area2, size;

        /// @brief Constructor
        /// @param area1 
        /// @param area2 
        /// @param size 
        overlap_info(int area1, int area2, int size)
        {
            this->area1 = area1;
            this->area2 = area2;
            this->size = size;
        }
};

int main()
{
    // get number of area ex. 4
    int number_of_areas;
    cin >> number_of_areas;

    // get areas ex. 
    // 2 4 6 6
    // 1 3 3 5
    // 1 1 3 2
    // 2 0 4 3
    vector<area> areas;
    for (int i = 0; i < number_of_areas; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        areas.push_back(area(x1, y1, x2, y2));
    }

    vector<overlap_info> overlaps;
    int max_overlap_size = 0;

    // find overlaps by compare area with other areas
    // area index 0, 1, 2, 3
    for (int i = 0; i < number_of_areas; i++)
    {
        // area index 0 will compare with area index 1, 2, 3
        // area index 1 will compare with area index 2, 3
        // area index 2 will compare with area index 3
        for (int j = i + 1; j < number_of_areas; j++)
        {
            // get overlap size
            int size = areas[i].overlap_size(areas[j]);
            if (size > 0)
            {
                overlap_info info = overlap_info(i, j, size);
                overlaps.push_back(info);

                // if max overlap size is smaller than current overlap size, update max overlap size
                max_overlap_size = max(max_overlap_size, size);
            }
        }
    }

    // print output
    if (overlaps.size() == 0)
    {
        cout << "No overlaps" << endl;
    }
    else
    {
        cout << "Max overlapping area = " << max_overlap_size << endl;
        for (int i = 0; i < overlaps.size(); i++)
        {
            // print only max overlap size
            if (overlaps[i].size == max_overlap_size)
            {
                cout << "rectangles " << overlaps[i].area1 << " and " << overlaps[i].area2 << endl;
                // cout << "  size = " << overlaps[i].size << endl;
            }
        }
    }
}