# Useful utils
* glxinfo
* clinfo

# Enviroment variables script
* source /opt/intel/oneapi/setvars.sh

# How to add intel repository for oneApi
* wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB \
                | gpg --dearmor | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
* echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" | sudo tee /etc/apt/sources.list.d/oneAPI.list
* sudo apt install intel-hpckit

# Lurk more:
* https://www.intel.com/content/www/us/en/developer/tools/oneapi/hpc-toolkit-download.html?operatingsystem=linux&distributions=aptpackagemanager
* https://www.intel.com/content/www/us/en/develop/documentation/installation-guide-for-intel-oneapi-toolkits-linux/top/installation/install-using-package-managers/apt.html
* https://www.intel.com/content/www/us/en/docs/oneapi/installation-guide-linux/2023-0/configure-wsl-2-for-gpu-workflows.html
* https://www.intel.com/content/www/us/en/docs/oneapi/installation-guide-linux/2023-0/install-intel-gpu-drivers.html#GUID-6837DD9B-D221-4A1A-927A-01A4E67796DD


# If you struggling to find good VPN
* tor &