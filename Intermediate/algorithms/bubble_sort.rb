#!/bin/ruby

puts "Enter numbers seperated by a space then press enter:"
a = gets.strip
a = a.split(' ').map(&:to_i)
n = a.count

sorted = true
sort_time = 0
while sorted
    sorted = false
    i = 0
    while i < n - 1
       if a[i] > a[i + 1]
           sorted = true
           a[i], a[i+1] = a[i+1], a[i]
           sort_time += 1
       end
        i += 1
    end
end

puts "Array is sorted in #{sort_time} swaps."
puts "Sorted Array: #{a}"