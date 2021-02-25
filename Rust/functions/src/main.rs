fn main() {
    println!("Hello, world!");

    another_function(5, 6);

    // let x = (let y = 6); //let是一个语句，没有返回值
    
    let x = 5;
    let y = {   //代码块是一个表达式，计算出的值是4
        let x = 3;
        x + 1   //注意没有分号!
    };
    println!("The value of x is {}", x);
    println!("The value of y is {}", y);

    let z = five();
    println!("The value of z is {}", z);

    let x = plus_one(x);
    println!("The value of x is {}", x);
}

fn another_function(x: i32, y: i32) {
    println!("Another function.");
    println!("The value of x is {}", x);
    println!("The value of y is {}", y);
}

fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
