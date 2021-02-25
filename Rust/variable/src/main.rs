fn main() {
    /* variables and constants */
    let x = 5;
    println!("The value of x is: {}", x);
    // x = 6;   //变量默认不可改变
    println!("The value of x is: {}", x);

    let mut y = 5;
    println!("The value of y is: {}", y);
    y = 6;
    println!("The value of y is: {}", y);

    const MAX_POINTS: u32 = 100;
    println!("The value of MAX_POINTS is {}", MAX_POINTS);

    /* shadowing */
    let z = 5;
    let z = z + 1;
    let z = z * 2;  //可以改变变量的值
    println!("The value of z is: {}", z);

    let spaces = "   ";
    let spaces = spaces.len();  //可以改变变量的类型
    println!("The value of spaces is: {}", spaces);

    // let mut spaces = "   ";
    // spaces = spaces.len();
}
