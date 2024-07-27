
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (nums.at(mid) == 2)
        {
            nums.at(mid) = nums.at(mid) + nums.at(high);
            nums.at(high) = nums.at(mid) - nums.at(high);
            nums.at(mid) = nums.at(mid) - nums.at(high);
            high--;
        }
        if (nums.at(mid) == 0)
        {
            nums.at(mid) = nums.at(mid) + nums.at(low);
            nums.at(low) = nums.at(mid) - nums.at(low);
            nums.at(mid) = nums.at(mid) - nums.at(low);
            low++;
            mid++;
        }
        if (nums.at(mid) == 1)
        {
            mid++;
        }
    }