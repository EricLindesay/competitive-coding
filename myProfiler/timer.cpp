#include <iostream>
#include <utility>
#include <type_traits>

// https://stackoverflow.com/questions/28498852/c-function-decorator

template <class T>
struct RetWrapper {
    template <class Tfunc, class... Targs>
    RetWrapper(Tfunc &&func, Targs &&... args)
    : val(std::forward<Tfunc>(func)(std::forward<Targs>(args)...)) {}
    
    T &&value() { return static_cast<T &&>(val); }
    
private:
    T val;
};

template <>
struct RetWrapper<void> {
    template <class Tfunc, class... Targs>
    RetWrapper(Tfunc &&func, Targs &&... args) {
        std::forward<Tfunc>(func)(std::forward<Targs>(args)...);
    }
    
    void value() {}
};

template <class Tfunc, class Tbefore, class Tafter>
auto decorate(Tfunc &&func, Tbefore &&before, Tafter &&after) {
    return [
    
        func = std::forward<Tfunc>(func),
        before = std::forward<Tbefore>(before),
        after = std::forward<Tafter>(after)
        
    ] (auto &&... args) -> decltype(auto) {
            
        before(std::forward<decltype(args)>(args)...);
        RetWrapper<std::result_of_t<Tfunc(decltype(args)...)>> ret(
            func, std::forward<decltype(args)>(args)...
        );
        after(std::forward<decltype(args)>(args)...);
        
        return ret.value();
    };
}

template <class Tfunc, class Tbefore, class Tafter>
auto decorate_narg(Tfunc &&func, Tbefore &&before, Tafter &&after) {
    return [
    
        func = std::forward<Tfunc>(func),
        before = std::forward<Tbefore>(before),
        after = std::forward<Tafter>(after)
        
    ] (auto &&... args) -> decltype(auto) {
            
        before();
        RetWrapper<std::result_of_t<Tfunc(decltype(args)...)>> ret(
            func, std::forward<decltype(args)>(args)...
        );
        after();
        
        return ret.value();
    };
}

template<class Tfunc>
auto decorate(Tfunc &&func) {
    return [
        func = std::forward<Tfunc>(func)
    ] (auto &&... args) -> decltype(auto) {
        RetWrapper<std::result_of_t<Tfunc(decltype(args)...)>> ret(
            func, std::forward<decltype(args)>(args)...
        );
        return ret.value();
    };
}

//template<class decT>
class Profile {
public:
	/*
    template <class Tfunc, class... Targs>
	Profile(Tfunc &&func, Targs &&... args) : val(std::forward<Tfunc>(func)(std::forward<Targs>(args)...)) {

	}
		
    T &&value() { return static_cast<T &&>(val); }
	*/
	template<class Tfunc>
	Profile(Tfunc &&func) {
		//decorated = std::forward(func);
//		decorated = decorate(func,
//				[] { std::cout << "Before" << std::endl; },
//				[] { std::cout << "After" << std::endl; });
//		decorated(std::forward<decltype(args)>(args)...);
		//decorated(std::forward<decltype(args)>(args)...);
	}

	template<class Tfunc, class... Targs>
	Profile(Tfunc &&func, Targs &&... args) {
		auto d = decorate_narg(func,
				[]{ std::cout << "Wrapper Before" << std::endl; },
				[]{ std::cout << "Wrapper After" << std::endl; });
		std::cout << "Start" << std::endl;
		d(std::forward<Targs>(args)...);
		std::cout << "End" << std::endl;
	}

private:
	//decT decorated;
};

/**
 * Have a function which can generate a Profile
 */
template <class Tfunc, class... Targs>
auto generateProfile(Tfunc func, Targs &&... args) {
//	auto d = decorate(func, 
//			[] {},
//			[] {});
//	return Profile<decltype(decorate(d))>(func);
	return Profile(func, std::forward<Targs>(args)...);
}

/*
 * Tests
 */

float test1(float a, float b) {
    std::cout << "Inside test1\n";
    return a * b;
}

void test2() {
    std::cout << "Inside test2\n";
}

int i = 0;

int &test3() {
    return i;
}

// timer::Timer timer();
// timer.start();
int factorial(int a) {
	// timer::checkpoint("Unique Name")
	std::cout << "Factorial: " << a << std::endl;
	if (a == 1)
		return a;
	return a * factorial(a-1);
}
// timer.stop();

int main() {

	/*
    auto test1Deco = decorate(
        test1,
        [] (float a, float b) {
            std::cout << "Calling test1 with " << a << " and " << b << '\n';
        },
        [] (float a, float b) {
            std::cout << "Called test1 with " << a << " and " << b << '\n';
        }
    );*/

	float c =0;
    //auto test1Deco = decorate(factorial);
	//auto profiled = Profile(factorial);
	auto profiled = generateProfile(factorial, 4);
	std::cout << "After test1Deco " << c << std::endl;

    return 0;
}
