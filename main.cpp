#include <fstream>
#include <iomanip>
#include <string>
#include "cn.h" //include the language header file
#include "lib/giwscli.h"

using namespace giwscli;

#define output_string() {std::cout << countx + 1 << "(" << five_star_assurance_number << ")(" << four_star_assurance_number << ") ";\
                    casesx( kind );\
                    std::cout << pname[kind] << '\n'; \
                    pcount[kind]++;\
                    wishes_number--;\
                    countx++;\
                    five_star_assurance_number++;\
                    four_star_assurance_number++;\
                    } // cout what have come home
#define luckcpy() {if ( luck > luckiest || countx < 11) {\
                        luckiest = luck;\
                        for (size_t templuck = 0; templuck < 10; templuck++) {\
                            luckiestlocation[templuck] = lucklocation[templuck];\
                            luckiestsublocation[templuck] = lucksublocation[templuck];\
                            luckiestsubsublocation[templuck] = lucksubsublocation[templuck];\
                            luckiestkind[templuck] = luckkind[templuck];\
                        }\
                    }\
                } // snapshot the luckiest moment
#define luckget() {for (size_t templuck = 0; templuck < 9; templuck++) {\
                        lucklocation[templuck] = lucklocation[templuck + 1];\
                        lucksublocation[templuck] = lucksublocation[templuck + 1];\
                        lucksubsublocation[templuck] = lucksubsublocation[templuck + 1];\
                        luckkind[templuck] = luckkind[templuck + 1];\
                        luckstar[templuck] = luckstar[templuck + 1];\
                    }\
                    lucklocation[9] = countx;\
                    lucksublocation[9] = static_cast<size_t> (five_star_assurance_number) - 1;\
                    lucksubsublocation[9] = static_cast<size_t> (four_star_assurance_number) - 1;\
                    luckkind[9] = kind;\
                    luckstar[9] = star;\
                    luck = 0;\
                } // get the recorded luckiest

using namespace std;

bool y_arg = false;
size_t luck = 0,
luckiest = 0,
one_to_ten[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
std::chrono::system_clock::time_point starty = std::chrono::system_clock::now();
std::chrono::system_clock::time_point endy = std::chrono::system_clock::now();
std::chrono::nanoseconds elapsed = starty - endy;
std::time_t t_start = std::chrono::system_clock::to_time_t(starty);
std::time_t t_end = std::chrono::system_clock::to_time_t(endy);
static size_t four_stars_c[23] = { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 71, 91, 95, 100, 106, 108 },
four_stars_w[27] = { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 79, 80, 82, 83, 84, 88, 102, 103, 104 },
five_stars_c[23] = { 0, 1, 2, 3, 4, 63, 64, 65, 66, 67, 68, 69, 70, 72, 86, 89, 90, 94, 96, 99, 105, 109, 111 },
five_stars_w[28] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 73, 74, 75, 76, 77, 78, 81, 85, 87, 92, 93, 97, 98, 101, 107, 110, 112, 113 },
luckkind[10] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 },
luckstar[10] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
luckiestkind[10] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 },
lucklocation[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
lucksublocation[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
lucksubsublocation[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
luckiestlocation[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
luckiestsublocation[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
luckiestsubsublocation[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
signed long long int  wishes_number = 0;
auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

static const char* pname[128] = { C_0, C_1, C_2, C_3, C_4, C_5, C_6, C_7, C_8, C_9, C_10, C_11, C_12, C_13, C_14, C_15, C_16, C_17, C_18, C_19, C_20,
				C_21, C_22, C_23, C_24, C_25, C_26, C_27, C_28, C_29, C_30, C_31, C_32, C_33, C_34, C_35, C_36, C_37, C_38, C_39, C_40,
				C_41, C_42, C_43, C_44, C_45, C_46, C_47, C_48, C_49, C_50, C_51, C_52, C_53, C_54, C_55, C_56, C_57, C_58, C_59, C_60,
				C_61, C_62, C_63, C_64, C_65, C_66, C_67, C_68, C_69, C_70, C_71, C_72, C_73, C_74, C_75, C_76, C_77, C_78, C_79, C_80,
				C_81, C_82, C_83, C_84, C_85, C_86, C_87, C_88, C_89, C_90, C_91, C_92, C_93, C_94, C_95, C_96, C_97, C_98, C_99, C_100,
				C_101, C_102, C_103, C_104, C_105, C_106, C_107, C_108, C_109, C_110, C_111, C_112, C_113, C_114,
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
};
static const char* pnameshort[128] = { X_0, X_1, X_2, X_3, X_4, X_5, X_6, X_7, X_8, X_9, X_10, X_11, X_12, X_13, X_14, X_15, X_16, X_17, X_18, X_19, X_20,
				X_21, X_22, X_23, X_24, X_25, X_26, X_27, X_28, X_29, X_30, X_31, X_32, X_33, X_34, X_35, X_36, X_37, X_38, X_39, X_40,
				X_41, X_42, X_43, X_44, X_45, X_46, X_47, X_48, X_49, X_50, X_51, X_52, X_53, X_54, X_55, X_56, X_57, X_58, X_59, X_60,
				X_61, X_62, X_63, X_64, X_65, X_66, X_67, X_68, X_69, X_70, X_71, X_72, X_73, X_74, X_75, X_76, X_77, X_78, X_79, X_80,
				X_81, X_82, X_83, X_84, X_85, X_86, X_87, X_88, X_89, X_90, X_91, X_92, X_93, X_94, X_95, X_96, X_97, X_98, X_99, X_100,
				X_101, X_102, X_103, X_104, X_105, X_106, X_107, X_108, X_109, X_110, X_111, X_112, X_113, X_114,
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
				"Placeholder",
};
// names of the items

static void casesx(size_t kind_p) {
  if (kind_p < 15) {
    std::cout << "!!!!!***** ";
  } else if (kind_p < 50) {
    std::cout << "!!**** ";
  } else if (kind_p < 63) {
    std::cout << "*** ";
  } else if (kind_p == 71 || kind_p == 79 || kind_p == 80 || kind_p == 82 ||
             kind_p == 83 || kind_p == 84 || kind_p == 88 || kind_p == 91 ||
             kind_p == 95 || kind_p == 100 || kind_p == 102 || kind_p == 103 ||
             kind_p == 104 || kind_p == 106 || kind_p == 108) {
    std::cout << "!!**** ";
  } else if (kind_p < 115) {
    std::cout << "!!!!!***** ";
  }
	else { std::cout << E_1 << "  "; }
} // cout stars prefix

static void ini_all(size_t* in, size_t ins, size_t nu) {
	for (size_t i = 0; i < ins; i++) { in[i] = nu; }
}

int main(int argc, char* argv[]) {
	std::ofstream ofs{ "output.txt" };
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(ofs.rdbuf());
	static char default_argv0[] = "giwscli";
	if (!argv[0] || !argv[0][0])
		argv[0] = default_argv0;
	quit = true;
	is_noelle = true;
	five_star_guarantee_number = false;
	four_star_guarantee_number = false;
	chosen_banner = 0;
	chosen_event = 0;
	four_star_assurance_number = 1;
	five_star_assurance_number = 1;
	max_fives = 1;
	min_fives = PTRDIFF_MAX;
	fate_weapon = 0;
	fate_points = 0;
	five_weight = 0;
	four_weight = 0;
	three_weight = 0;
	unmet4_c = 0;
	unmet4_w = 0;
	unmet5_c = 0;
	unmet5_w = 0;
	resultt = 0;
	resultu = 0;
	luck = 0;
	luckiest = 0;
	size_nup_four_w = 18;
	countx = 0;
	wishes_number = 0;
	five_count = 0;
	five_count_c = 0;
	five_count_w = 0;
	four_count = 0;
	four_count_c = 0;
	four_count_w = 0;
	ave_fives = 0;
	max_fivesth = 1;
	min_fivesth = 1;
	max_fivecount = 1;
	min_fivecount = 1;
	ini_all(up_five_g, 2, 0);
	ini_all(up_four_g, 16, 0);
	ini_all(nup_four_c, 32, 0);
	for (size_t i = 0; i < 10; i++) { luckstar[i] = 3; }
	ini_all(luckiestkind, 10, 127);
	ini_all(five_check, 8, 127);
	ini_all(four_check, 8, 127);
	ini_ams(lucklocation, 10, one_to_ten);
	ini_ams(lucksublocation, 10, one_to_ten);
	ini_ams(lucksubsublocation, 10, one_to_ten);
	ini_ams(luckiestlocation, 10, one_to_ten);
	ini_ams(luckiestsublocation, 10, one_to_ten);
	ini_ams(luckiestsubsublocation, 10, one_to_ten);
	ini_all(pcount, 128, 0);
	ini_all(four_pity, 11, 0);
	ini_all(five_pity, 90, 0);
	ini_all(five_pity_w, 80, 0);
	if (argc == 4) {
		int test0 = 0;
		int test1 = 0;
		long long int test2 = 0;
		try {
			test0 = stoi(argv[1]);
			test1 = stoi(argv[2]);
			test2 = stoll(argv[3]);
		}
		catch (...) {
			std::cout << E_11 << '\n';
			y_arg = true;
			goto full_quit;
		}
		test0 = std::stoi(argv[1]);
		test1 = std::stoi(argv[2]);
		test2 = std::stoll(argv[3]);
		chosen_banner = static_cast<ptrdiff_t>(test0);
		chosen_event = static_cast<ptrdiff_t>(test1);
		if (test2 < 1) {
			std::cout << S_72 << '\n';
			y_arg = true;
			goto full_quit;
		}
		else { wishes_number = test2; }
		quit = false;
		y_arg = true;
		goto set_banner;
	}
	else {
		std::cout << E_11 << '\n';
		y_arg = true;
		goto full_quit;
	}
set_banner:
	set_banner_f(chosen_banner, chosen_event);
	std::cout << S_1 << '\n' << S_2 << '\n' << S_3 << '\n' << S_4 << "\n\n" << S_85 << "\n\n";
	starty = std::chrono::system_clock::now();
	if (chosen_banner == 1 || chosen_banner == 2) {
		while (wishes_number > 0) {
			temp1 = generatorz() % 2;
			star = 0; //4-star or 5-star
			type = 0; //Up or non-up, character or weapon
			kind = 0; //which exactly
            core_f_1();
			output_string()
				if (star != 4 || type == 3) unmet4_c++;
			if (star != 4 || type != 3) unmet4_w++;
			if (y_arg) {
				luckget()
					if (star == 4 || star == 5) {
						for (const size_t templuck : luckstar) {
							if (templuck == 5) luck += 6232;
							else if (templuck == 4) luck += 766;
							else luck += 0;
						}
					}
				luckcpy()
			}
		}
	}
	else if (chosen_banner == 3) {
		while (wishes_number > 0) {
            temp1 = generatorz() % 4;
            star = 0;  // 4-star or 5-star
            type = 0;  // Up or non-up, character or weapon
            kind = 0;  // which exactly
            core_f_3();
			output_string()
				if (star != 4 || type == 3) unmet4_c++;
			if (star != 4 || type != 3) unmet4_w++;
			if (y_arg) {
				luckget()
					if (star == 4 || star == 5) {
						for (const size_t templuck : luckstar) {
							if (templuck == 5) luck += 5328;
							else if (templuck == 4) luck += 674;
							else luck += 0;
						}
					}
				luckcpy()
			}
		}
	}
	else if (chosen_banner == 4) {
		while (wishes_number > 0) {
            star = 0;  // 4-star or 5-star
            type = 0;  // Up or non-up, character or weapon
            kind = 0;  // which exactly
            core_f_3();
			output_string()
				if (!(star == 5 && type == 1)) unmet5_c++;
			if (!(star == 5 && type == 2)) unmet5_w++;
			if (!(star == 4 && type == 1)) unmet4_c++;
			if (!(star == 4 && type == 2)) unmet4_w++;
			if (y_arg) {
				luckget()
					if (star == 4 || star == 5) {
						for (const size_t templuck : luckstar) {
							if (templuck == 5) luck += 6232;
							else if (templuck == 4) luck += 766;
							else luck += 0;
						}
					}
				luckcpy()
			}
		}
	}
	else if (chosen_banner == 5) {
		while (wishes_number > 0) {
            temp1 = generatorz() % 1000;
            star = 0;  // 4-star or 5-star
            kind = 0;  // which exactly
            core_f_1();
			output_string()
				if (y_arg) {
					luckget()
						if (star == 4 || star == 5) {
							for (const size_t templuck : luckstar) {
								if (templuck == 5) luck += 16667;
								else if (templuck == 4) luck += 766;
								else luck += 0;
							}
						}
					luckcpy()
				}
		}
	}
	else { std::cout << E_7 << '\n'; goto full_quit; }
	// real work
	quit = true;
	endy = std::chrono::system_clock::now();
	elapsed = endy - starty;
	elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	t_start = std::chrono::system_clock::to_time_t(starty);
	t_end = std::chrono::system_clock::to_time_t(endy);
	std::cout << '\n' << S_86 << t_start << '\n';
	std::cout << S_87 << t_end << '\n';
	std::cout << static_cast<double>(elapsed_time) * 1.0 / 1000000 << S_84 << '\n';
	if (five_count == 0) {
		std::cout << '\n' << S_73 << countx << S_74 << '\n'
			<< S_75 << five_count << "  " << static_cast<double>(five_count) * 100.0 / static_cast<double>(countx) << "%\n"
			<< S_76 << four_count << "  " << static_cast<double>(four_count) * 100.0 / static_cast<double>(countx) << "%\n"
			<< S_77 << five_count_c << " : " << five_count_w << " : " << four_count_c << " : " << four_count_w << "\n\n";
	}
	else {
		std::cout << '\n' << S_73 << countx << S_74 << '\n'
			<< S_75 << five_count << "  " << static_cast<double>(five_count) * 100.0 / static_cast<double>(countx) << "%\n"
			<< S_76 << four_count << "  " << static_cast<double>(four_count) * 100.0 / static_cast<double>(countx) << "%\n"
			<< S_78 << max_fives << S_79 << max_fivesth << S_80 << max_fivecount + 1 << S_81 << '\n'
			<< S_82 << min_fives << S_79 << min_fivesth << S_80 << min_fivecount + 1 << S_81 << '\n'
			<< S_83 << static_cast<double>(ave_fives) * 1.0 / static_cast<double>(five_count) << '\n'
			<< S_77 << five_count_c << " : " << five_count_w << " : " << four_count_c << " : " << four_count_w << "\n\n";
	}
	for (const size_t iout : five_stars_c) { if (pcount[iout] > 0) std::cout << pnameshort[iout] << "(" << pcount[iout] << ") "; }
	for (const size_t iout : five_stars_w) { if (pcount[iout] > 0) std::cout << pnameshort[iout] << "(" << pcount[iout] << ") "; }
	if (five_count > 0) { std::cout << "\n\n"; }
	for (const size_t iout : four_stars_c) { if (pcount[iout] > 0) std::cout << pnameshort[iout] << "(" << pcount[iout] << ") "; }
	for (const size_t iout : four_stars_w) { if (pcount[iout] > 0) std::cout << pnameshort[iout] << "(" << pcount[iout] << ") "; }
	std::cout << "\n\n";
	if (countx < 10) { std::cout << S_62 << '\n'; goto print_1; }
	std::cout << S_63 << luckiest << '\n';
	for (size_t templuck = 0; templuck < 10; templuck++) {
		std::cout << luckiestlocation[templuck] << "(" << luckiestsublocation[templuck] << ")(" << luckiestsubsublocation[templuck] << ") ";
		casesx(luckiestkind[templuck]);
		std::cout << pname[luckiestkind[templuck]] << '\n';
	}
print_1:
	std::cout << '\n';
	if (chosen_banner == 5 || four_count == 0 || five_count == 0) { wishes_number = 0; std::cout << S_72 << '\n'; goto print_2; }
	else if (chosen_banner == 1 || chosen_banner == 2 || chosen_banner == 4) {
		std::cout << S_88 << "\n\n";
		std::cout << std::fixed << std::setprecision(8);
		for (size_t iout = 0; iout < 10; iout++) { std::cout << iout + 1 << "  " << four_pity[iout] << "   " << static_cast<double>(four_pity[iout]) * 100.0 / static_cast<double>(four_count) << "%\n"; }
		std::cout << "10+  " << four_pity[10] << "   " << static_cast<double>(four_pity[10]) * 100.0 / static_cast<double>(four_count) << "%\n\n" << S_89 << "\n\n";
		for (size_t iout = 0; iout < 90; iout++) { std::cout << iout + 1 << "  " << five_pity[iout] << "   " << static_cast<double>(five_pity[iout]) * 100.0 / static_cast<double>(five_count) << "%\n"; }
		std::cout << std::defaultfloat;
		wishes_number = 0;
		goto print_2;
	}
	else if (chosen_banner == 3) {
		std::cout << S_88 << "\n\n";
		std::cout << std::fixed << std::setprecision(8);
		for (size_t iout = 0; iout < 10; iout++) { std::cout << iout + 1 << "  " << four_pity[iout] << "   " << static_cast<double>(four_pity[iout]) * 100.0 / static_cast<double>(four_count) << "%\n"; }
		std::cout << "10+  " << four_pity[10] << "   " << static_cast<double>(four_pity[10]) * 100.0 / static_cast<double>(four_count) << "%\n\n" << S_89 << "\n\n";
		for (size_t iout = 0; iout < 80; iout++) { std::cout << iout + 1 << "  " << five_pity_w[iout] << "   " << static_cast<double>(five_pity_w[iout]) * 100.0 / static_cast<double>(five_count) << "%\n"; }
		std::cout << std::defaultfloat;
		wishes_number = 0;
		goto print_2;
	}
	else {
		wishes_number = 0; std::cout << E_7 << '\n'; goto full_quit;
	}
print_2:
	if (y_arg) goto full_quit;
full_quit:
	std::cout.rdbuf(coutbuf);
	return 0;
}