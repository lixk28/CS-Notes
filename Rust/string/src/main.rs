fn main() {
    let mut s = String::from("hello");
    s.push_str(", world!"); //在字符串后面追加值
    println!("{}", s);

    let s1 = String::from("hello");
    let s2 = s1;
    // println!("string s1: {}", s1);   //s1无效
    println!("string s2: {}", s2);

    let s3 = String::from("I am Groot.");
    let s4 = s3.clone();    //复制String堆上的数据
    println!("string s3: {}", s3);
    println!("string s4: {}", s4);

    let x = 5;  //copy trait
    let y = x;
    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
}
