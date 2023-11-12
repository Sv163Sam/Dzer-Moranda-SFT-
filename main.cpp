#include "main.h"

void work_6(const int *data)
{
    std::cout << "---VAR 14---\n" << std::endl;
    std::cout << "---Работа 6---" << std::endl;
    std::cout << "В работе исследуются алгоритмы, определяющие момент остановки отладки(Достижение ПО требуемой надежности).\n"
                 "За основу взята модель Джелинского-Моранды. В частности, частота проявления ошибок пропорциональна числу оставшихся ошибок.\n"
                 "Интенсивность: dn/dt = K * (N0 - n)\nK - пропорциональность, N0 - общее кол-во ошибок, n - найденные ошибки\n"
                 "Для корректной реализации, нужно рассмотреть решение удовлетворяющее всей совокупности эксперемантальных данных\n"
                 "Таким образом, мы определяем значение неизвестных N0, K, исходя из минимизации квадратов невязок между эксперементальными\n"
                 "данным и теоретическими по модели delta(nj), где nj - приращение обнаруженного количества ошибок на delta(t)\n" << std::endl;
    std::cout << "Исходные данные:" << std::endl;
    for(int i = 0; i < 7; i++)
    {
        std::cout << "Момент времени ti(дни): " << i + 1 << " | Количество ошибок на delta(nj): " << data[i] << std::endl;
    }
};

void work_7(const int *data)
{
    int ti = 0, delta_nj = 0, i = 0;
    double eps = 0.0001, N0 = 0.0, sum_left = 0.0, res_right = 0.0, sum_exp = 0.0, sum_dnj = 0.0, sum_ti = 0.0, delta_k = 0.25, k = 0.0;

    do
    {
        sum_left = 0.0;
        sum_exp = 0.0;
        sum_dnj = 0.0;
        sum_ti = 0.0;
        k += delta_k;
        std::cout << "\n\n" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "|                          |" << std::endl;
        std::cout << "|           k=" << k << "         |" << std::endl;
        std::cout << "|                          |" << std::endl;
        std::cout << "----------------------------\n" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|    |           |              |        |           |                     |                |               |                        |" << std::endl;
        std::cout << "| ti | delta(nj) | ti*delta(nj) |  k*ti  | e^(-k*ti) | delta(nj)*e^(-k*ti) | ti*e^(-k*ti*2) | (e^(-k*ti))^2 | delta(nj)*ti*e^(-k*ti) |" << std::endl;
        std::cout << "|    |           |              |        |           |                     |                |               |                        |" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        while(i < 7)
        {
            ti += 1;
            delta_nj = data[i++];
            sum_left +=  delta_nj * ti * exp((-k)*ti);
            sum_exp += exp((-k)*ti) * exp((-k)*ti);
            sum_ti += ti * exp((-k)*ti*2);
            sum_dnj += delta_nj * exp((-k)*ti);
            if(i == 6)
                res_right = sum_dnj * sum_ti / sum_exp;

            std::cout << "| " << ti << "  |    " << delta_nj << "      |      " << ti * delta_nj << "      |  " << k * ti <<
            "  |    " << exp((-k)*ti) << "    |     " << delta_nj * exp((-k)*ti) << "      |    " << ti * exp((-k)*ti*2) <<
            "   |    d" << exp((-k)*ti) * exp((-k)*ti) << "    |        " << delta_nj * ti * exp((-k)*ti) << "       |" << std::endl;
            std::cout << "--------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        }
        i = 0;
        ti = 0;
        std::cout << "Sum_left: " << sum_left << ", sum_nj: " << sum_dnj << ", sum_ti: " << sum_ti << ", sum_exp: " << sum_exp << std::endl;
    } while(abs(sum_left) - abs(res_right) > eps);

    std::cout << "\n\n" << std::endl;
    N0 = sum_left / (k * (1/k) * sum_ti);
    std::cout << "N0 - " << N0 << " k - " << k << std::endl;
    //std::cout << "Nofit: " << delta_nj - N0 * k * 1/k * exp((-k)*ti) << std::endl;
    //std::cout << "Square sum: " << (delta_nj - N0 * k * 1/k * exp((-k)*ti)) * (delta_nj - N0 * k * 1/k * exp((-k)*ti)) << std::endl;
    std::cout << "Изменение K: " << std::endl;
    for(int j = 0; j < k/0.25 + 1; j++)
    {
        std::cout << j*0.25 << std::endl;
    }
}

int main()
{
    int data[] = { 3, 4, 3, 3, 2, 2, 0 };

    // ---Работа 6---
    work_6(data);

    //Касаемо 7 работы там не построены графики
    //8 и 9 работа, это целиком анализ
    //тебе я видоизменить код могу но тут касаемо логики меня совсем мало, поэтому лучше сам над графиком поработай
    //остался ток анализ на питоне

    // ---Работа 7---
    work_7(data);

    return 0;
}