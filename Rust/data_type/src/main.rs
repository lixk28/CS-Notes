fn main() {
    let tup: (i32, f64, bool) = (100, 3.2, true);

    let (x, y, z) = tup;    //pattern matching

    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
    println!("The value of z is: {}", z);

    println!("The value of x is: {}", tup.0);   //indexing
    println!("The value of y is: {}", tup.1);
    println!("The value of z is: {}", tup.2);

    let a: [i32; 5] = [1, 2, 3, 4, 5];

    let first = a[0];
    let second = a[1];

    println!("The first element in array is: {}", first);
    println!("The second element in array is: {}", second);
}
