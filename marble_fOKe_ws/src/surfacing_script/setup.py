import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'surfacing_script'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dzeks',
    maintainer_email='dzeks@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'talker = surfacing_script.publisher_member_function:main',
                'surfacing_controller = surfacing_script.surfacing_controller:main',
                'geofloater = surfacing_script.geocaller:main',
                'localization = surfacing_script.deadreckon:main',
                "univerzalni_node = surfacing_script.univerzalni_node:main",
        ],
    },
)
