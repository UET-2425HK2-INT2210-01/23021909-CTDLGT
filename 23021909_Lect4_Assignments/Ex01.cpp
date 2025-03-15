// What are two desirable properties of a hash function?

// Tính đồng nhất (Uniformity): Hàm băm phải phân phối các giá trị đầu ra một cách đồng
// đều. Điều này giúp giảm thiểu khả năng xảy ra va chạm (collision), nơi hai giá trị 
// khác nhau lại có cùng kết quả băm.

// Tính một chiều (Pre-image resistance): Dễ dàng tính toán giá trị băm từ dữ liệu đầu
// vào, nhưng rất khó (hoặc không thể) để tìm lại dữ liệu đầu vào ban đầu từ giá trị
// băm đã cho.