from random import shuffle


def main():
    int_list = [i for i in range(200)]
    shuffle(int_list)
    print(int_list, "\n")

    bubble_sort(int_list)
    print(int_list)


def bubble_sort(nums: list[int]) -> list[int]:
    swapping = True
    end = len(nums)
    while swapping:
        swapping = False
        for i in range(1, end):
            if nums[i-1] > nums[i]:
                nums[i], nums[i-1] = nums[i-1], nums[i]
                swapping = True
        end -= 1
    return nums


if __name__ == "__main__":
    main()
