import os
from glob import glob
from setuptools import setup

package_name = 'marble_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='adna',
    maintainer_email='adna@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
    'console_scripts': [
        'inference = marble_pkg.inference_node:main',
        'tracking = marble_pkg.tracking_node:main',
        'gnss_conversion = marble_pkg.gnss_with_floater_info:main'
        ]
    },
)
