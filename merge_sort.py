class Car:  
    def __init__(self, make, model, year):  
        self.make = make  
        self.model = model  
        self.year = year  
  
    def __str__(self):  
        return str.format("Make: {}, Model: {}, Year: {}", self.make, self.model, self.year)  
  
def merge(list1, l, r, m, comp_fun):  
    left_copy = list1[l:m + 1]  
    r_sublist = list1[m+1:r+1]  
  
    left_copy_index = 0  
    r_sublist_index = 0  
    sorted_index = l  
  
    while left_copy_index < len(left_copy) and r_sublist_index < len(r_sublist):  
  
        # We use the comp_fun instead of a simple comparison operator  
        if comp_fun(left_copy[left_copy_index], r_sublist[r_sublist_index]):  
            list1[sorted_index] = left_copy[left_copy_index]  
            left_copy_index = left_copy_index + 1  
        else:  
            list1[sorted_index] = r_sublist[r_sublist_index]  
            r_sublist_index = r_sublist_index + 1  
  
        sorted_index = sorted_index + 1  
  
    while left_copy_index < len(left_copy):  
        list1[sorted_index] = left_copy[left_copy_index]  
        left_copy_index = left_copy_index + 1  
        sorted_index = sorted_index + 1  
  
    while r_sublist_index < len(r_sublist):  
        list1[sorted_index] = r_sublist[r_sublist_index]  
        r_sublist_index = r_sublist_index + 1  
        sorted_index = sorted_index + 1  
  
  
def merge_sort(list1, l, r, comp_fun):  
    if l >= r:  
        return  
  
    m = (l + r)//2  
    merge_sort(list1, l, m, comp_fun)  
    merge_sort(list1, m + 1, r, comp_fun)  
    merge(list1, l, r, m, comp_fun)  
  
car1 = Car("Renault", "33 Duster", 2001)  
car2 = Car("Maruti", "Maruti Suzuki Dzire", 2015)  
car3 = Car("Tata motor", "Jaguar", 2004)  
car4 = Car("Cadillac", "Seville Sedan", 1995)  
  
list1 = [car1, car2, car3, car4]  
  
merge_sort(list1, 0, len(list1) -1, lambda carA, carB: carA.year < carB.year)  
  
print("Cars sorted by year:")  
for car in list1:  
    print(car)  
  
print()  
merge_sort(list1, 0, len(list1) -1, lambda carA, carB: carA.make < carB.make)  
print("Cars sorted by make:")  
for car in list1:  
    print(car)  