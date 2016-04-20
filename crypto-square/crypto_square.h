#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H
#include <string>
#include <vector>


namespace crypto_square {

class cipher {
    std::string __plain_text;
    std::string __normalized_text;
    
    std::string normalize_text_helper();
public:
    cipher(std::string input);
    
    std::string normalize_plain_text() const;
    std::size_t size() const;
    
    std::vector<std::string> plain_text_segments() const;
    std::string normalized_cipher_text() const;
    std::string cipher_text() const;
};

} // namespace crypto_square

#endif // CRYPTO_SQUARE_H