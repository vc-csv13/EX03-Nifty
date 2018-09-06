## Exercise: WindChillIndex (25 Points)

The objective of this project is to create your first C++ function and familiarize your self with creating applications from scratch.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions 
[here](https://github.com/vcc-csv13-fall2018/HowToStartEveryProject)
to get started. 

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

In cold weather, meteorologists report an index called the wind chill factor , which
takes into account the wind speed and the temperature. The index provides a
measure of the chilling effect of wind at a given air temperature. Wind chill may
be approximated by the following formula,

<svg height='28.6767pt' version='1.1' viewBox='-0.239051 -0.229996 208.197 28.6767' width='208.197pt' xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink'>
<defs>
<path d='M7.87846 -2.74969C8.08169 -2.74969 8.29689 -2.74969 8.29689 -2.98879S8.08169 -3.2279 7.87846 -3.2279H1.41071C1.20747 -3.2279 0.992279 -3.2279 0.992279 -2.98879S1.20747 -2.74969 1.41071 -2.74969H7.87846Z' id='g0-0'/>
<path d='M4.65056 10.2217L2.54645 5.57111C2.46276 5.37983 2.40299 5.37983 2.36712 5.37983C2.35517 5.37983 2.29539 5.37983 2.16389 5.47547L1.02814 6.33624C0.872727 6.45579 0.872727 6.49166 0.872727 6.52752C0.872727 6.5873 0.908593 6.65903 0.992279 6.65903C1.06401 6.65903 1.26725 6.49166 1.39875 6.39601C1.47049 6.33624 1.64981 6.20473 1.78132 6.10909L4.13649 11.2857C4.22017 11.477 4.27995 11.477 4.38755 11.477C4.56687 11.477 4.60274 11.4052 4.68643 11.2379L10.1141 0C10.1978 -0.167372 10.1978 -0.215193 10.1978 -0.239103C10.1978 -0.358655 10.1021 -0.478207 9.95866 -0.478207C9.86301 -0.478207 9.77933 -0.418431 9.68369 -0.227148L4.65056 10.2217Z' id='g0-112'/>
<path d='M3.88543 2.90511C3.88543 2.86924 3.88543 2.84533 3.68219 2.64209C2.48667 1.43462 1.81719 -0.537983 1.81719 -2.97684C1.81719 -5.29614 2.37908 -7.29265 3.76588 -8.70336C3.88543 -8.81096 3.88543 -8.83487 3.88543 -8.87073C3.88543 -8.94247 3.82565 -8.96638 3.77783 -8.96638C3.62242 -8.96638 2.64209 -8.1056 2.05629 -6.934C1.44658 -5.72653 1.17161 -4.44732 1.17161 -2.97684C1.17161 -1.91283 1.33898 -0.490162 1.96065 0.789041C2.666 2.22366 3.64633 3.00075 3.77783 3.00075C3.82565 3.00075 3.88543 2.97684 3.88543 2.90511Z' id='g2-40'/>
<path d='M3.37136 -2.97684C3.37136 -3.88543 3.25181 -5.36787 2.58232 -6.75467C1.87696 -8.18929 0.896638 -8.96638 0.765131 -8.96638C0.71731 -8.96638 0.657534 -8.94247 0.657534 -8.87073C0.657534 -8.83487 0.657534 -8.81096 0.860772 -8.60772C2.05629 -7.40025 2.72578 -5.42765 2.72578 -2.98879C2.72578 -0.669489 2.16389 1.32702 0.777086 2.73773C0.657534 2.84533 0.657534 2.86924 0.657534 2.90511C0.657534 2.97684 0.71731 3.00075 0.765131 3.00075C0.920548 3.00075 1.90087 2.13998 2.48667 0.968369C3.09639 -0.251059 3.37136 -1.54222 3.37136 -2.97684Z' id='g2-41'/>
<path d='M4.77011 -2.76164H8.06974C8.23711 -2.76164 8.4523 -2.76164 8.4523 -2.97684C8.4523 -3.20399 8.24907 -3.20399 8.06974 -3.20399H4.77011V-6.50361C4.77011 -6.67098 4.77011 -6.88618 4.55492 -6.88618C4.32777 -6.88618 4.32777 -6.68294 4.32777 -6.50361V-3.20399H1.02814C0.860772 -3.20399 0.645579 -3.20399 0.645579 -2.98879C0.645579 -2.76164 0.848817 -2.76164 1.02814 -2.76164H4.32777V0.537983C4.32777 0.705355 4.32777 0.920548 4.54296 0.920548C4.77011 0.920548 4.77011 0.71731 4.77011 0.537983V-2.76164Z' id='g2-43'/>
<path d='M5.35592 -3.82565C5.35592 -4.81793 5.29614 -5.7863 4.86575 -6.69489C4.37559 -7.68717 3.51482 -7.95019 2.92902 -7.95019C2.23562 -7.95019 1.3868 -7.60349 0.944458 -6.61121C0.609714 -5.85803 0.490162 -5.11681 0.490162 -3.82565C0.490162 -2.666 0.573848 -1.79328 1.00423 -0.944458C1.47049 -0.0358655 2.29539 0.251059 2.91706 0.251059C3.95716 0.251059 4.55492 -0.37061 4.90162 -1.06401C5.332 -1.96065 5.35592 -3.13225 5.35592 -3.82565ZM2.91706 0.0119552C2.5345 0.0119552 1.75741 -0.203238 1.53026 -1.50635C1.39875 -2.22366 1.39875 -3.13225 1.39875 -3.96912C1.39875 -4.94944 1.39875 -5.83412 1.59004 -6.53948C1.79328 -7.34047 2.40299 -7.71108 2.91706 -7.71108C3.37136 -7.71108 4.06476 -7.43611 4.29191 -6.40797C4.44732 -5.72653 4.44732 -4.78207 4.44732 -3.96912C4.44732 -3.16812 4.44732 -2.25953 4.31582 -1.53026C4.08867 -0.215193 3.33549 0.0119552 2.91706 0.0119552Z' id='g2-48'/>
<path d='M3.44309 -7.66326C3.44309 -7.93823 3.44309 -7.95019 3.20399 -7.95019C2.91706 -7.6274 2.3193 -7.18506 1.08792 -7.18506V-6.83836C1.36289 -6.83836 1.96065 -6.83836 2.61818 -7.14919V-0.920548C2.61818 -0.490162 2.58232 -0.3467 1.53026 -0.3467H1.15965V0C1.48244 -0.0239103 2.64209 -0.0239103 3.03661 -0.0239103S4.57883 -0.0239103 4.90162 0V-0.3467H4.53101C3.47895 -0.3467 3.44309 -0.490162 3.44309 -0.920548V-7.66326Z' id='g2-49'/>
<path d='M5.26027 -2.00847H4.99726C4.96139 -1.80523 4.86575 -1.1477 4.7462 -0.956413C4.66252 -0.848817 3.98107 -0.848817 3.62242 -0.848817H1.41071C1.7335 -1.12379 2.46276 -1.88892 2.7736 -2.17584C4.59078 -3.84956 5.26027 -4.47123 5.26027 -5.65479C5.26027 -7.02964 4.17235 -7.95019 2.78555 -7.95019S0.585803 -6.76663 0.585803 -5.73848C0.585803 -5.12877 1.11183 -5.12877 1.1477 -5.12877C1.39875 -5.12877 1.70959 -5.30809 1.70959 -5.69066C1.70959 -6.0254 1.48244 -6.25255 1.1477 -6.25255C1.0401 -6.25255 1.01619 -6.25255 0.980324 -6.2406C1.20747 -7.05355 1.85305 -7.60349 2.63014 -7.60349C3.64633 -7.60349 4.268 -6.75467 4.268 -5.65479C4.268 -4.63861 3.68219 -3.75392 3.00075 -2.98879L0.585803 -0.286924V0H4.94944L5.26027 -2.00847Z' id='g2-50'/>
<path d='M2.19975 -4.29191C1.99651 -4.27995 1.94869 -4.268 1.94869 -4.1604C1.94869 -4.04085 2.00847 -4.04085 2.22366 -4.04085H2.7736C3.78979 -4.04085 4.24408 -3.20399 4.24408 -2.05629C4.24408 -0.490162 3.43113 -0.071731 2.84533 -0.071731C2.27148 -0.071731 1.29116 -0.3467 0.944458 -1.13574C1.32702 -1.07597 1.67372 -1.29116 1.67372 -1.72154C1.67372 -2.06824 1.42267 -2.30735 1.08792 -2.30735C0.800996 -2.30735 0.490162 -2.13998 0.490162 -1.68568C0.490162 -0.621669 1.55417 0.251059 2.8812 0.251059C4.30386 0.251059 5.35592 -0.836862 5.35592 -2.04433C5.35592 -3.14421 4.47123 -4.00498 3.32354 -4.20822C4.36364 -4.5071 5.03313 -5.37983 5.03313 -6.31233C5.03313 -7.25679 4.0528 -7.95019 2.89315 -7.95019C1.69763 -7.95019 0.812951 -7.22092 0.812951 -6.34819C0.812951 -5.86999 1.18356 -5.77435 1.36289 -5.77435C1.61395 -5.77435 1.90087 -5.95367 1.90087 -6.31233C1.90087 -6.69489 1.61395 -6.86227 1.35093 -6.86227C1.2792 -6.86227 1.25529 -6.86227 1.21943 -6.85031C1.67372 -7.66326 2.79751 -7.66326 2.85729 -7.66326C3.25181 -7.66326 4.02889 -7.48394 4.02889 -6.31233C4.02889 -6.08518 3.99303 -5.41569 3.64633 -4.90162C3.28767 -4.37559 2.8812 -4.33973 2.55841 -4.32777L2.19975 -4.29191Z' id='g2-51'/>
<path d='M1.53026 -6.85031C2.04433 -6.68294 2.46276 -6.67098 2.59427 -6.67098C3.94521 -6.67098 4.80598 -7.66326 4.80598 -7.83064C4.80598 -7.87846 4.78207 -7.93823 4.71034 -7.93823C4.68643 -7.93823 4.66252 -7.93823 4.55492 -7.89041C3.88543 -7.60349 3.31158 -7.56762 3.00075 -7.56762C2.21171 -7.56762 1.64981 -7.80672 1.42267 -7.90237C1.33898 -7.93823 1.31507 -7.93823 1.30311 -7.93823C1.20747 -7.93823 1.20747 -7.8665 1.20747 -7.67522V-4.12453C1.20747 -3.90934 1.20747 -3.83761 1.35093 -3.83761C1.41071 -3.83761 1.42267 -3.84956 1.54222 -3.99303C1.87696 -4.48319 2.43885 -4.77011 3.03661 -4.77011C3.67024 -4.77011 3.98107 -4.18431 4.07671 -3.98107C4.27995 -3.51482 4.29191 -2.92902 4.29191 -2.47472S4.29191 -1.33898 3.95716 -0.800996C3.69415 -0.37061 3.2279 -0.071731 2.70187 -0.071731C1.91283 -0.071731 1.13574 -0.609714 0.920548 -1.48244C0.980324 -1.45853 1.05205 -1.44658 1.11183 -1.44658C1.31507 -1.44658 1.63786 -1.56613 1.63786 -1.9726C1.63786 -2.30735 1.41071 -2.49863 1.11183 -2.49863C0.896638 -2.49863 0.585803 -2.39103 0.585803 -1.92478C0.585803 -0.908593 1.39875 0.251059 2.72578 0.251059C4.07671 0.251059 5.26027 -0.884682 5.26027 -2.40299C5.26027 -3.82565 4.30386 -5.00922 3.04857 -5.00922C2.36712 -5.00922 1.8411 -4.71034 1.53026 -4.37559V-6.85031Z' id='g2-53'/>
<path d='M8.06974 -3.87347C8.23711 -3.87347 8.4523 -3.87347 8.4523 -4.08867C8.4523 -4.31582 8.24907 -4.31582 8.06974 -4.31582H1.02814C0.860772 -4.31582 0.645579 -4.31582 0.645579 -4.10062C0.645579 -3.87347 0.848817 -3.87347 1.02814 -3.87347H8.06974ZM8.06974 -1.64981C8.23711 -1.64981 8.4523 -1.64981 8.4523 -1.86501C8.4523 -2.09215 8.24907 -2.09215 8.06974 -2.09215H1.02814C0.860772 -2.09215 0.645579 -2.09215 0.645579 -1.87696C0.645579 -1.64981 0.848817 -1.64981 1.02814 -1.64981H8.06974Z' id='g2-61'/>
<path d='M2.19975 -0.573848C2.19975 -0.920548 1.91283 -1.15965 1.6259 -1.15965C1.2792 -1.15965 1.0401 -0.872727 1.0401 -0.585803C1.0401 -0.239103 1.32702 0 1.61395 0C1.96065 0 2.19975 -0.286924 2.19975 -0.573848Z' id='g1-58'/>
<path d='M2.40299 -4.80598H3.50286C3.73001 -4.80598 3.84956 -4.80598 3.84956 -5.02117C3.84956 -5.15268 3.77783 -5.15268 3.53873 -5.15268H2.48667L2.92902 -6.89813C2.97684 -7.0655 2.97684 -7.08941 2.97684 -7.1731C2.97684 -7.36438 2.82142 -7.47198 2.666 -7.47198C2.57036 -7.47198 2.29539 -7.43611 2.19975 -7.05355L1.7335 -5.15268H0.609714C0.37061 -5.15268 0.263014 -5.15268 0.263014 -4.92553C0.263014 -4.80598 0.3467 -4.80598 0.573848 -4.80598H1.63786L0.848817 -1.64981C0.753176 -1.23138 0.71731 -1.11183 0.71731 -0.956413C0.71731 -0.394521 1.11183 0.119552 1.78132 0.119552C2.98879 0.119552 3.63437 -1.6259 3.63437 -1.70959C3.63437 -1.78132 3.58655 -1.81719 3.51482 -1.81719C3.49091 -1.81719 3.44309 -1.81719 3.41918 -1.76936C3.40722 -1.75741 3.39527 -1.74545 3.31158 -1.55417C3.06052 -0.956413 2.51059 -0.119552 1.81719 -0.119552C1.45853 -0.119552 1.43462 -0.418431 1.43462 -0.681445C1.43462 -0.6934 1.43462 -0.920548 1.47049 -1.06401L2.40299 -4.80598Z' id='g1-116'/>
<path d='M5.46351 -4.47123C5.46351 -5.22441 5.08095 -5.27223 4.98531 -5.27223C4.69838 -5.27223 4.43537 -4.98531 4.43537 -4.7462C4.43537 -4.60274 4.51905 -4.51905 4.56687 -4.47123C4.68643 -4.36364 4.99726 -4.04085 4.99726 -3.41918C4.99726 -2.91706 4.27995 -0.119552 2.84533 -0.119552C2.11606 -0.119552 1.9726 -0.729265 1.9726 -1.17161C1.9726 -1.76936 2.24757 -2.60623 2.57036 -3.467C2.76164 -3.95716 2.80946 -4.07671 2.80946 -4.31582C2.80946 -4.81793 2.45081 -5.27223 1.86501 -5.27223C0.765131 -5.27223 0.32279 -3.53873 0.32279 -3.44309C0.32279 -3.39527 0.37061 -3.33549 0.454296 -3.33549C0.561893 -3.33549 0.573848 -3.38331 0.621669 -3.55068C0.908593 -4.57883 1.37484 -5.03313 1.82914 -5.03313C1.93674 -5.03313 2.13998 -5.03313 2.13998 -4.63861C2.13998 -4.32777 2.00847 -3.98107 1.82914 -3.52677C1.25529 -1.99651 1.25529 -1.6259 1.25529 -1.33898C1.25529 -1.07597 1.29116 -0.585803 1.66177 -0.251059C2.09215 0.119552 2.68991 0.119552 2.79751 0.119552C4.78207 0.119552 5.46351 -3.78979 5.46351 -4.47123Z' id='g1-118'/>
<path d='M4.11258 -0.729265C4.37559 -0.0119552 5.11681 0.119552 5.57111 0.119552C6.4797 0.119552 7.01768 -0.669489 7.35243 -1.4944C7.6274 -2.1878 8.06974 -3.76588 8.06974 -4.47123C8.06974 -5.2005 7.69913 -5.27223 7.59153 -5.27223C7.30461 -5.27223 7.04159 -4.98531 7.04159 -4.7462C7.04159 -4.60274 7.12528 -4.51905 7.18506 -4.47123C7.29265 -4.36364 7.60349 -4.04085 7.60349 -3.41918C7.60349 -3.0127 7.26874 -1.88892 7.01768 -1.32702C6.68294 -0.597758 6.2406 -0.119552 5.61893 -0.119552C4.94944 -0.119552 4.73425 -0.621669 4.73425 -1.17161C4.73425 -1.51831 4.84184 -1.93674 4.88966 -2.13998L5.39178 -4.14844C5.45156 -4.38755 5.55915 -4.80598 5.55915 -4.8538C5.55915 -5.03313 5.41569 -5.15268 5.23636 -5.15268C4.88966 -5.15268 4.80598 -4.8538 4.73425 -4.56687C4.61469 -4.10062 4.11258 -2.0802 4.06476 -1.81719C4.01694 -1.61395 4.01694 -1.48244 4.01694 -1.21943C4.01694 -0.932503 3.63437 -0.478207 3.62242 -0.454296C3.49091 -0.32279 3.29963 -0.119552 2.92902 -0.119552C1.98456 -0.119552 1.98456 -1.01619 1.98456 -1.21943C1.98456 -1.60199 2.06824 -2.12802 2.60623 -3.55068C2.74969 -3.9213 2.80946 -4.07671 2.80946 -4.31582C2.80946 -4.81793 2.45081 -5.27223 1.86501 -5.27223C0.765131 -5.27223 0.32279 -3.53873 0.32279 -3.44309C0.32279 -3.39527 0.37061 -3.33549 0.454296 -3.33549C0.561893 -3.33549 0.573848 -3.38331 0.621669 -3.55068C0.920548 -4.60274 1.3868 -5.03313 1.82914 -5.03313C1.94869 -5.03313 2.13998 -5.02117 2.13998 -4.63861C2.13998 -4.57883 2.13998 -4.32777 1.93674 -3.80174C1.37484 -2.30735 1.25529 -1.81719 1.25529 -1.36289C1.25529 -0.107597 2.28344 0.119552 2.89315 0.119552C3.09639 0.119552 3.63437 0.119552 4.11258 -0.729265Z' id='g1-119'/>
</defs>
<g id='page1' transform='matrix(1.13 0 0 1.13 -63.986 -61.5624)'>
<use x='56.4133' xlink:href='#g1-119' y='71.4534'/>
<use x='68.3924' xlink:href='#g2-61' y='71.4534'/>
<use x='80.7838' xlink:href='#g2-51' y='71.4534'/>
<use x='86.615' xlink:href='#g2-51' y='71.4534'/>
<use x='95.1028' xlink:href='#g0-0' y='71.4534'/>
<use x='108.219' xlink:href='#g2-40' y='63.3657'/>
<use x='112.754' xlink:href='#g2-49' y='63.3657'/>
<use x='118.585' xlink:href='#g2-48' y='63.3657'/>
<use x='124.416' xlink:href='#g0-112' y='54.7546'/>
<rect height='0.478187' width='6.08821' x='134.379' y='54.2764'/>
<use x='134.379' xlink:href='#g1-118' y='63.3657'/>
<use x='143.124' xlink:href='#g0-0' y='63.3657'/>
<use x='155.044' xlink:href='#g1-118' y='63.3657'/>
<use x='163.768' xlink:href='#g2-43' y='63.3657'/>
<use x='175.495' xlink:href='#g2-49' y='63.3657'/>
<use x='181.326' xlink:href='#g2-48' y='63.3657'/>
<use x='187.158' xlink:href='#g1-58' y='63.3657'/>
<use x='190.397' xlink:href='#g2-53' y='63.3657'/>
<use x='196.228' xlink:href='#g2-41' y='63.3657'/>
<use x='200.763' xlink:href='#g2-40' y='63.3657'/>
<use x='205.299' xlink:href='#g2-51' y='63.3657'/>
<use x='211.13' xlink:href='#g2-51' y='63.3657'/>
<use x='219.618' xlink:href='#g0-0' y='63.3657'/>
<use x='231.538' xlink:href='#g1-116' y='63.3657'/>
<use x='235.749' xlink:href='#g2-41' y='63.3657'/>
<rect height='0.478187' width='132.44' x='108.219' y='68.2255'/>
<use x='164.033' xlink:href='#g2-50' y='79.6541'/>
<use x='169.864' xlink:href='#g2-51' y='79.6541'/>
<use x='175.695' xlink:href='#g1-58' y='79.6541'/>
<use x='178.935' xlink:href='#g2-49' y='79.6541'/>
</g>
</svg>

where

_v_ = wind speed in m/sec \
_t_ = temperature in degrees Celsius: t 6= 10 \
_w_ = wind chill index (in degrees Celsius)

Write a function that returns the wind chill index. Your code should ensure that
the restriction on the temperature is not violated. Look up some weather reports
in back issues of a newspaper in your library and compare the wind chill index you
calculate with the result reported in the newspaper.

### Writing the code for this Project

Writing the code for this project is very simple. You will create three files: a header and implementation of a function, and an implementation of main to test your personally test your code.

#### computeWindChillIndex

This function will compute the wind chill index (and return it as a `double`) based on two input parameters (of type `double`), the current temperature, in C, and the wind speed in m/s. This index is valid only for temperatures below 10 degrees C, inclusive. If the temperature is greater than that, then the function should return -1 to indicate invalid input.

To create this function you'll need a header file with a declaration so it can be used in other code, and an implementation file with the C++ code of this function.

##### windchillindex.h

First you'll need to create windchillindex.h. This is the only file that must be named exactly this. If you misspell, or use differenct capitalization, the test program will not compile.

In CLion in the project explorer, right-click the `include` directory
and chose `New => C++ Header File`. 

Under **Name** fill in
windchillindex. CLion will add the `.h` extension. Press **OK**. You should now see the file `windchillindex.h` in
the project explorer in the `include` directory.

Write your declaration of the `computerWindChillIndex` in here in the `edu::sbcc::cs140` namepspace.

##### Implementation

Next you'll need to create the implementation, separately from the declaration, of the computeWindChillIndex. This can be done in any file in the `src` directory as long as it has the extension `.cc` and is not named `main.cc`. 

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
windchillindex (or any other name besides `main`). CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `windchillindex.cc` (or whatever you named the file) in
the project explorer in the `src` directory.

Write your implementation of the `computerWindChillIndex` in here in the `edu::sbcc::cs140` namepspace.

#### main()

If you want to test this code yourself, without using the unit tests, which I recommend for at least the first few projects, then you will need to create a `main()` function in a file named `main.cc` in the `src` directory. It is very important that you name it exactly this way, or things might not compile properly.

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
main. CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `main.cc` in
the project explorer in the `src` directory.

Your main function should look something like this:

```cpp
#include "windchillindex.h"

int main() {
  // Put your code here that calls computeWindChillIndex with some valid input and write the result to the terminal.
  
  return 0;
}
```

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `WindChillIndex | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
/Users/username/githubusername/ex02-windchillindex/cmake-build-debug/bin/WindChillIndex
The wind chill index is: 11.5

Process finished with exit code 0
```
Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `WindChillIndex_Gtest` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
/home/aknight/xormasters/ex02-windchillindex/cmake-build-debug/bin/WindChillIndex_GTest
Running main() from gtest_main.cc
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from WindChillIndexTest
[ RUN      ] WindChillIndexTest.Basic
[       OK ] WindChillIndexTest.Basic (0 ms)
[ RUN      ] WindChillIndexTest.TemperatureOutOfRange
[       OK ] WindChillIndexTest.TemperatureOutOfRange (0 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 2 tests from WindChillIndexTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.

Process finished with exit code 0

```

Remember, You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

At the bottom of CLion there should be a view tab labeled **Version Control**.
Select this tab at the bottom of the screen. You should see a tab called **Local Changes**.
Under **Unversion Files** you should have one file: `main.cc`.
Select these files and right-click on them. In the drop-down menu
select **Add to VCS**. Next, right-click on these files again, which should
now be under **Default** and select **Commit**. Add the appropriate
commit message and click **OK**. Finally, right click on the committed files,
select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/vcc-csv13-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
