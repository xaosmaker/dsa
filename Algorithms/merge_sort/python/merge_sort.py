from random import shuffle


def main():
    int_list = [i for i in range(200)]
    shuffle(int_list)
    print(int_list, "\n")

    print(merge_sort(int_list))


def merge_sort(data: list[int]) -> list[int]:
    if len(data) < 2:
        return data

    middle = len(data) // 2

    sorted_left_side = merge_sort(data[:middle])
    sorted_right_side = merge_sort(data[middle:])

    return merge(sorted_left_side, sorted_right_side)


def merge(sorted_left: list[int], sorted_right: list[int]):
    final = []
    i, j = 0, 0

    while i < len(sorted_left) and j < len(sorted_right):
        if sorted_left[i] < sorted_right[j]:
            final.append(sorted_left[i])
            i += 1
        else:

            final.append(sorted_right[j])
            j += 1
    while i < len(sorted_left):
        final.append(sorted_left[i])
        i += 1
    while j < len(sorted_right):
        final.append(sorted_right[j])
        j += 1
    return final


if __name__ == "__main__":
    main()
