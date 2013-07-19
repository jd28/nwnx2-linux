#ifndef TALIB_CUSTOM_ATTRIBUTE_H
#define TALIB_CUSTOM_ATTRIBUTE_H

class Attribute {
    int32_t base_;
    int32_t effect_;
    
public:
    enum selector {
        BASE,
        EFFECT,
        BOTH
    };

    Attribute()
        : Attribute(0, 0)
        {}
    
    Attribute(int32_t base, int32_t effect)
        : base_(base)
        , effect_(effect)
        {}

    void set(int32_t value, selector s);
    int32_t modify(int32_t amount, selector s = EFFECT);
    int32_t get(selector s = BOTH);
};

inline void Attribute::set(int32_t value, Attribute::selector s) {
    switch(s) {
    case BASE:   base_ = value; break;
    case EFFECT: effect_ = value; break;
    case BOTH:   base_ = value; effect_ = value; break;
    }
}

inline int32_t Attribute::modify(int32_t amount, Attribute::selector s) {
    switch(s) {
    case BASE:   base_ += amount; break;
    case EFFECT: effect_ += amount; break;
    case BOTH:   base_ += amount; effect_ += amount; break;
    }
    return get(s);
}
    
inline int32_t Attribute::get(Attribute::selector s) {
    switch(s) {
    default:     return 0;
    case BASE:   return base_;
    case EFFECT: return effect_;
    case BOTH:   return base_ + effect_;
    }
}

#endif // TALIB_CUSTOM_ATTRIBUTE_H
